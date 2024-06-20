t = int(input())


for i in range(t):
    
    a, b, c, d = tuple(map(int, input().split()))
    one = min(a, b)
    two = max(a, b)
    if one < c < two and one < d < two: 
        print("NO")
    elif (two < c <= 12 or 1 <= c < one) and (two < d <= 12 or 1 <= d < one):
        print("NO")
    else:
        print("YES")