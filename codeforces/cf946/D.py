
from collections import defaultdict

t = int(input()) 

for _ in range(t):
    n = int(input())

    arr = input()

    d = defaultdict(lambda: 0)
    r = defaultdict(lambda: 0)
    h = defaultdict(lambda: 0)

    for c in arr:
        d[c] += 1
    
    if n % 2 == 1:
        print("NO")
        continue

    if (d['N'] + d['S']) % 2 == 1:
        print("NO")
        continue
    elif (d['W'] + d['E']) % 2 == 1:
        print("NO")
        continue

    # print(d)

    r['N'] = d['N'] // 2;
    r['S'] = d['S'] // 2;
    h['N'] = r['N'];
    h['S'] = r['S'];
    if (d['N'] % 2 == 1):
        h['N'] += 1;
        h['S'] += 1;

    r['W'] = d['W'] // 2;
    r['E'] = d['E'] // 2;
    h['W'] = r['W'];
    h['E'] = r['E'];
    if (d['W'] % 2 == 1):
        if (r['N'] == 0 and r['W'] == 0 and r['E'] == 0 and r['S'] == 0):
            r['W'] += 1
            r['E'] += 1
        else:
            h['W'] += 1
            h['E'] += 1

    if r['N'] == 0 and r['S'] == 0 and r['W'] == 0 and r['E'] == 0:
        print("NO")
        continue
    elif h['N'] == 0 and h['S'] == 0 and h['W'] == 0 and h['E'] == 0:
        print("NO")
        continue

    for c in arr:
        if r[c] > 0:
            print('R', end='')
            r[c] -= 1
        else:
            print('H', end='')
            h[c] -= 1
    print()