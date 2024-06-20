(n, q) = tuple(map(int, input().split(" ")))

# teams[i] = i, for parents.
teams = [i for i in range(n + 1)]
th = [i for i in range(n + 1)]

def find(teams, x):
    root = x
    # while teams[root] != root:
    #     root = teams[root]

    # while teams[x] != root:
    #     parent = teams[x]
    #     teams[x] = root
    #     x = parent
    # return root

    if teams[root] != root:
        teams[root] = find(teams, teams[root])
    return teams[root]

for _ in range(int(q)):
    (a, b, c) = tuple(map(int, input().split(" ")))
    b -= 1
    c -= 1
    if a == 3:
        pb = find(teams, b)
        pc = find(teams, c)
        if pc == pb:
            print("YES")
        else:
            print("NO")

    if a == 2:
        x = b
        y = c
        while True:
            # Find in the help array
            # Set the help array and also set the middle teams array
            x = find(th, x)
            if (x >= y):
                break
            pb = find(teams, x)
            pc = find(teams, x + 1)
            teams[pb] = pc
            th[x] = x + 1
    
    if a == 1:
        pb = find(teams, b)
        pc = find(teams, c)
        teams[pb] = pc
# print(teams)
        
