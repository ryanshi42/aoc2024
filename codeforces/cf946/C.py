
from collections import defaultdict

t = int(input())

for _ in range(t):
    n = int(input())

    ans = 0
    arr = list(map(int, input().split()))

    xyz = defaultdict(lambda: 0)

    xys = defaultdict(lambda: 0)
    xzs = defaultdict(lambda: 0)
    yzs = defaultdict(lambda: 0)

    for i in range(2, n):
        (x, y, z) = (arr[i - 2], arr[i - 1], arr[i])
        ans += xys[(x, y)]
        ans += xzs[(x, z)]
        ans += yzs[(y, z)]
        ans -= xyz[(x, y, z)] * 3

        xyz[(x, y, z)] += 1
        xys[(x, y)] += 1
        xzs[(x, z)] += 1
        yzs[(y, z)] += 1
    # print("ans")
    print(ans)