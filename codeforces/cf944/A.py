t = int(input())


for i in range(t):
    
    a, b = tuple(map(int, input().split()))
    print(min(a, b), max(a, b))