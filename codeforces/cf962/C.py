from collections import Counter

t = int(input())

for _ in range(t):
    n, q = tuple(map(int, input().split()))
    a = input()
    b = input()


    da = []
    db = []
    # da.append(Counter(""))
    # db.append(Counter(""))
    va = [0 for _ in range(26)]
    vb = [0 for _ in range(26)]
    da.append(va[:])
    db.append(vb[:])
    for i in range(n):
        va[ord(a[i]) - ord('a')] += 1
        vb[ord(b[i]) - ord('a')] += 1
        da.append(va[:])
        db.append(vb[:])

    for _ in range(q):
        ans = 0
        l, r = tuple(map(int, input().split()))
        
        # print(da[r], da[l - 1])
        x = [da[r][v] - da[l - 1][v] for v in range(26)] 
        y = [db[r][v] - db[l - 1][v] for v in range(26)] 

        # print(x, y)

        for c in "qwertyuiopasdfghjklzxcvbnm":
            ans += abs(x[ord(c) - ord('a')] - y[ord(c) - ord('a')])

        print(ans // 2)