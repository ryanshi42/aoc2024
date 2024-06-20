t = int(input())


for _ in range(t):
    
    n = int(input())
    cols = [[] for _ in range(n)]

    for _ in range(3):
        col = list(map(int, input().split()))
        for j in range(len(col)):
            cols[j].append(col[j])

    print(cols)
    
