
from collections import defaultdict


t = int(input())

for _ in range(t):
    d = defaultdict(lambda : 0)

    ans = 0
    n, m = tuple(map(int, input().split()))

    for s in input().split():
        s = int(s)
        d[s] += 1

    d1 = dict(d)
    for a in d1.keys():
        for j in range(d[a] + 1):
            if (m < j * a): 
                break
            # print(j, a, min((m - j * a) // (a - 1), d[a - 1]))
            if (a > 1):
                ans = max(ans, j * a + (a - 1) * min((m - j * a) // (a - 1), d[a - 1]))
            ans = max(ans, j * a + (a + 1) * min((m - j * a) // (a + 1), d[a + 1]))

    print(int(ans))

