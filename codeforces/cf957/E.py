
M = 10

arr = [[] for _ in range(M)]

for n in range(1, M + 1):
    print(n)

    # subtract 1, 10, 100 can all take away one digit
    # n * a - b can go up to 100 * 10000 = 1000000 so just look at final 8 digits
    # for a in range(1, 10001):
    #     z = len(str(n))
    z = str(n) * 10
    for i in range(1, 10):
        aa = z[-i:]
        if aa[0] == "0":
            continue
        for b in range(10000):
            
        

    # arr[n - 1] = ans

print(arr)

t = int(input())

for _ in range(t):
    x = int(input())
    print(len(arr[x - 1]))
    for (a, b) in arr[x - 1]:
        print(a, b)