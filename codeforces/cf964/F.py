import math

t = int(input())

def mod(i):
    return i % (10 ** 9 + 7)

for _ in range(t):
    n, k = tuple(map(int, input().split()))

    ns = list(map(int, input().split()))

    ans = 0

    ones = 0
    zeros = 0
    for num in ns:
        if num == 1:
            ones += 1
        else:
            zeros += 1

    for i in range((k - 1) // 2 + 1, k + 1):
        nz = k - i
        if nz > zeros or i > ones:
            continue

        ans = mod(ans + mod(math.comb(zeros, nz)) * mod((math.comb(ones, i))))
    print(ans)

# from math import comb

# def mod(i):
#     return i % (1e9 + 7)

# t = int(input())

# for _ in range(t):
#     n, k = tuple(map(int, input().split()))
#     arr = list(map(int, input().split()))

#     ones = sum(arr)
#     zeros = len(arr) - ones 

#     res = 0

#     for i in range(k // 2 + 1):
#         n0, n1 = i, k - i

#         if zeros < n0 or ones < n1:
#             continue

#         res = mod(res + comb(zeros, n0) * comb(ones, n1))

#     res = res % (10 ** 9 + 7)
#     print(int(res))

# from math import comb
 
# t = int(input())

# def mod(i):
#     return i % (10 ** 9 + 7)

# for _ in range(t):
#     n, k = tuple(map(int, input().split()))
#     arr = list(map(int, input().split()))
 
#     ones = sum(arr)
#     zeros = len(arr) - ones 
 
#     res = 0
 
#     for i in range(k // 2 + 1):
#         n0, n1 = i, k - i
 
#         if zeros < n0 or ones < n1:
#             continue
 
#         res = mod(res + mod(comb(zeros, n0)) * mod(comb(ones, n1)))
 
#     print(int(res))