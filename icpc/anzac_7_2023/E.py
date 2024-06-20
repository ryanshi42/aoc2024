

P = int(input())

for _ in range(P):
    K, N = map(int, input().split())

    list = []

    while N != 1:
        list.append(N)
        N //= 2
    
    list = list[::-1]

    nu = 1
    de = 1
    for e in list:
        if e % 2 == 1:
            nu += de
        else:
            de += nu
    
    print(f'{K} {nu}/{de}')
    