n, c = tuple(map(int, input().split()))

items = []

from collections import defaultdict 

x = defaultdict(lambda: 0)
for i in range(c):
    upto, mp = tuple(map(int, input().split()))
    x[upto] = max(x[upto], mp)

ans = 0

t = x.items()
t = [(z[1] / z[0], z[0], z[1]) for z in t]
t.sort(reverse=True)

cs = 0

for (ratio, when, price) in t:
    cp = len(items)
    # already past
    if when <= cp:
        continue
    elif price <= cs:
        # already satisfied price
        continue
    else:
        price -= cs
        when -= cp
        # price = 6, when = 2 -> 3 3
        for i in range(when - 1):
            items.append(price // when)
            cs += price // when
            ans += (price // when) ** 2 
        if price % when:
            items.append(price % when)
            cs += price % when
            ans += (price % when) ** 2 
        else:
            items.append(price // when)
            cs += price // when
            ans += (price // when) ** 2 

# print(items)

print(ans)