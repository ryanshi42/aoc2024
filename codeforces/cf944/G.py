t = int(input())

from collections import defaultdict

for i in range(t):
    n = int(input())
    
    a = list(map(int, input().split()))
    eqv = defaultdict(list)

    mods = []
    for num in a:
        first = num >> 2
        mods.append(first)
        eqv[first].append(num)

    for v in eqv.values():
        v.sort(reverse=True)
    
    ans = []
    # print(eqv)
    for m in mods:
        ans.append(str(eqv[m][-1]))
        eqv[m].pop()
    print(" ".join(ans))

    
