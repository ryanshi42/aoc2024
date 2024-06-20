
t = int(input())

from bisect import bisect_left, bisect

for _ in range(t):
    (a, b, n, m) = tuple(map(int, input().split()))
    xs = []
    ys = []

    ap = 0
    bp = 0

    for i in range(n):
        (x, y) = tuple(map(int, input().split()))
        ys.append((y, x))
        xs.append((x, y))

    xs.sort()
    ys.sort()

    cx = (0, a)
    cy = (0, b)

    for i in range(m):
        (dir, k) = tuple(input().split())
        k = int(k)
        if dir == 'L':
            idx = bisect_left(xs, cx[0])
            idy = bisect(xs, cx[0] + k)

            for i in range(idx, idy):
                ap += 

            cx = (cx[0] + k, a)
    

    print(ans)