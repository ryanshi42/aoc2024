# VirtualDrive
Implement a virtual drive interface that abstracts over a set of physical hard drives. Each hard drive is 100 bytes. The first 100 virtual addresses correspond to the first hard drive (drive A), the second to hard drive B etc.

```
drive A: A0 A1 A2 ... A99
drive B: B0 B1 B2 ... B99 
drive C: C0 C1 C2 ... C99   
e.g. vaddr 102 = B2
```

## Part 1 - Basic Reading
The hard drive class is implemented for you:
```py
class HardDrive:
    def read(index) -> int:
        pass
```

You need to implement the `VirtualDrive` class:
```py
class VirtualDrive:
    def __init__(self, drives: List[HardDrive]):
        pass

    def read_vaddr(self, vaddr) -> int:
        pass
```

## Part 2 - Failure Recovery
You now want to deal with hard drive failure. The `read()` method of `HardDrive` now returns `Optional(int)`, and None is returned if the hard drive has encountered some kind of failure.

To aid with recovery, there is an additional hard drive in which each byte is the XOR of the bytes at the same index in each other hard drive:
```
drive X: X0 X1 X2 ... X99
 
X0 = A0 ^ B0 ^ C0
B0 = A0 ^ X0 ^ C0
```

In the case that a hard drive fails, you are able to recover it's original value by XOR'ing each of the other hard drives since XOR is reversible. Note that it is only possible to recover if there is at most one failed hard drive.

The `read_vaddr()` method of `VirtualDrive` should now also return a `Optional(int)` where None is returned in the case of a non-recoverable failure. You should implement the following helper function:
```py
# If possible, recover a byte given all same index bytes from other hard drives
def recover(List[Optional(int)]) -> Optional(int):
    pass
```

## Part 3 - Async Reads
We want to move from synchronous reads to asynchronous reads. You'll need to implement the following new methods on `VirtualDrive`:
```py
def start_read_vaddr(self, vaddr):
    pass

def on_drive_read_complete(self, drive, data: Optional[int])
    pass
```

The `HardDrive` gets a new method, which begins an asynchronous read and calls `on_drive_read_complete()` when finished. Note that you can only have one read at a time for each `HardDrive`.
```py
def start_read(index):
    pass
```

Once the read succeeds call the magic function `report_read_complete(vaddr, data)`, or if the read fails then call `report_read_failed(vaddr)`. You should try to recover first before reporting failure, which should also be done asynchronously.
