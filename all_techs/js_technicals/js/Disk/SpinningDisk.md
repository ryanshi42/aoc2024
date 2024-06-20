# Spinning Disk
Implement a file system that abstracts over a spinning disk. The interface for the disk is:
```
public class Disk {
    public Disk(int size);

    // Get the size of the disk
    public int size();

    // Write one character to disk at the position the disk head is currently at
    public void write(char ch);

    // Read one character from disk from the position the disk head is currently at
    public char read();

    // Get the current position of the disk head
    public int position();
}
```

You want to implement the FileSystem class:
```
class FileSystem {
    public FileSystem(Disk disk)
    
    // Begin the write of a file
    public void write(String filename, String data)
    
    // Begin the read of a file
    public void read(String filename);
    
    // Called whenever the disk rotates
    public void onSpin();
}
```

Importantly, this class must be **asynchronous**. This means:
- `write()` should not wait until the disk is rotated to point at an empty slot
- `read()` should not wait until the disk is rotated to the location of the file
To support asynchronous reads, a function `reportReadComplete(filename, data)` is given which should be called when the read of a file is complete. To make things simpler, we can assume that the first file written should always begin at position 0, and further files should be written contiguously behind the previous files.
