t = int(input())

from bisect import bisect_left

for i in range(t):
    
    n, k, q = tuple(map(int, input().split()))
    a = [0] + list(map(int, input().split())) 
    b = [0] + list(map(int, input().split()))
    x = []
    for i in range(q):
        d = int(input())
        idx = bisect_left(a, d)
        if a[idx] > d:
            idx -= 1
        if idx == len(a) - 1:
            x.append(str(b[idx]))
            continue
        # print("asbdjhflkadsh", d, a[idx], b[idx])
        val = b[idx] + ((d - a[idx]) * (b[idx + 1] - b[idx]) ) // (a[idx + 1] - a[idx])
        x.append(str(val))

    print(" ".join(x))
