t = int(input())


for i in range(t):
    s = input()
    invs = 0
    gs = []
    for i in range(len(s)):
        if gs and s[i] == gs[-1][0]:
            gs[-1][1] += 1
        else:
            gs.append([s[i], 1]) 

    if len(gs) == 1 or (len(gs) == 2 and gs[0][0] == '0'):
        print(1)
    elif len(gs) == 2:
        print(2)
    else:
        print(len(gs) - 1)


