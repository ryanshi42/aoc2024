
# from decimal import *
# daily_rate = 1
# rep_factor = 3
# getcontext().prec = 60 # set precision to 30

# x = Decimal(0)
# for i in range(20, 2036, 12):
#     x += Decimal(1 / (i * (i - 12)))

# print(x)

# x = 1

# # Need to include multiple of 4 in denominator
# for i in range(8, 2036, 12):
#     x *= i

# print(x)

# for y in range(20, 2036, 12):
#     y += x // (i * (i - 12))

# print()
# print(y)
# print()
# print(x)
# print()
# for i in range(2, y):
#     print(x, y)
#     while y % i == 0 and x % i == 0:
#         y //= i
#         x //= i
# print()
# # print(y/x)

# x = 12

# print(12, 12 * (1/8 - 1/2024), (2024 - 8), 12 * 8 * 2024, 24192 / 16192)

# dad's side has none AND mums side has none
# dadside = (1/6 + 2/6 * 0.9 + 3/6 * 0.9 * 0.9) 
# dadside = (100 + 180 + 243)
# mumside = (1/4 + 1/4 * 0.9 + 1/4 * 0.9 * 0.9 + 1/4 * 0.9 * 0.9 * 0.9)
# mumside = (1000 + 900 + 810 + 729)
# z = 2400000 - dadside * mumside
# print(z)

# z = 1 - (0.9 * 0.9) * (0.9 * 0.9 * 0.9)
# print(z)

# fff
# fee
# dde
# cde
# cdb
# ccb
# abb
# aaa



# N, W = map(int, input().split())

# ans = 0
# if W == 2:
#     ans += 1 * (N % 2) + 4 * (N // 2)
# else:
#     ans += (N % 6) + 8 * (N // 6)
#     if N % 6 == 5 or N % 6 == 4:
#         ans += 1

# print(ans)

# 6
# 5 2 3 10 2 6

# N = int(input())
# nums = map(int, input().split())
# nums = list(nums)

# from collections import defaultdict

# # e = [(i, x) for (i, x) in enumerate(nums)]
# c = defaultdict(lambda: 0)
# # for (i, x) in e:
# #     c[x].append(i)

# # for k in c.keys():
# #     c[k].sort()

# # # print(c)

# ans = 0
# for i in range(N - 1, -1, -1):
#     num = nums[i]
#     c[num] += 1
#     for j in range(0, i):
#         prod = c[nums[j]] * c[nums[i]]
#         ans += c[prod]
# # for (i, x) in e:
# #     for (j, y) in e:
# #         if j <= i:
# #             continue
# #         # print(x, y)
# #         z = x * y
# #         if z in c:
# #             ans += len([l for l in c[z] if j < l])

# print(ans)


N = int(input())
m = map(int, input().split())

m = list(m)

a = max(m) + 1 
# find all prime numbers between 0 and a
primes = []
ans = sum(m) 

blah = 0

for i in primes:
    temp = 0
    for num in m:
        temp += num % i
    # print(temp)
    if ans > temp: 
        ans = temp
        blah = i

print(ans)
# print(blah)


# 2 to find second smallest of two elements
# 2 to find second largest of two elements

# find the max of the two potentially smallest elements
# (1, 2) (1, 3)




from collections import deque

(N, M) = tuple(map(int, input().split()))
(start, end) = tuple(map(int, input().split()))

from collections import defaultdict
edges = defaultdict(lambda: defaultdict(lambda: set()))
tstocols = defaultdict(lambda: set())


for i in range(M):
    (ts, te, col) = tuple(map(int, input().split())) 
    edges[te][col].add((ts, col, 0))
    tstocols[te].add(col)

# print(tstocols, edges)

q = deque()
for scol in tstocols[te]:
    q.extend(list(edges[te][scol]))

visited = set()

while q:
    (cs, currcol, currlvl) = q.popleft()
    if (cs, currcol) in visited:
        continue
    visited.add((cs, currcol))

    # print(cs, tstocols[cs])
    if cs == start:
        print(currlvl)
        exit(0)
    for newcol in list(tstocols[cs]):
        if currcol == newcol:
            for (e, c, l) in edges[cs][newcol]:
                q.push_front((e, c, currlvl))
        else:
            for (e, c, l) in edges[cs][newcol]:
                q.append((e, c, currlvl + 1))
    

print("IMPOSSIBLE")

# 5 5
# 1 5
# 1 2 1
# 2 3 2
# 3 4 1
# 4 5 2
# 1 4 1

# from collections import Counter

# N = int(input())
# nums = list(map(int, input().split()))
# c = Counter(nums)
# ans = 0
# for j in range(N):
#     numj = nums[j]
#     c[numj] -= 1
#     for i in range(j):
#         numi = nums[i]
#         ans += c[numi * numj]
# print(ans)



# x cannot be 0 and y cannot be -1, and f(x) cannot be -y.

# Substitute x = 1, y = 0. Then f(f(1)) = 1 + f(f(1)), which cannot exist unless f(f(1)) = infinity, which cannot hold unless f(1) = 0 (by examining the range of f). 
# More specifically, 1 is in the domain of f so f maps 1 to another number in the reals, say x, then f(x) is undefined, so therefore x is necessarily not in the domain of f and hence f(1) = 0.
# If this is not the case then no functions exist.

# Henceforth we do not consider x = 1 and y = 0 as y + f(x) = 0. Consider now y = 0 and consider any x, which satisfies the conditions e.g. x(y + 1) != 0. Then f(f(x)) = 1 + x(f(f(x)). We get that f(f(x)) = 1 / (1 - x), with an undefined point at x = 1. 
# # Also then for some variable y, f(f(1 + y)) = - 1 / y = - f(f(1 - y)). 

# Consider now x = 1 and consider any y which satisfies the conditions. Then we have that
# f(y + f(1)) = 1 + f(f(y + 1)) = 1 - 1/y = (y-1)/y. In particular when y = 1 we have that f(1 + f(1)) = 0.
# Also since f(1) = 0 from before (else no functions exist) then we have that f(y) = (y - 1) / y.

# Indeed f(f(y)) = ((y - 1) - y) / (y - 1) = 1 / (1 - y), from before, and the domain and range of f are exactly that of this function.

# Then for some z not equal to 0, we have that z + f(1 + f(1)) = z. Both of these are within the domain of f so take f again to obtain that:
# f(z + f(1 + f(1))) = f(z). Therefore f is a class of periodic functions with period f(1 + f(1)).

# Note that the (y-1)/y covers all of R except when is equal to 0. We must also check that f(y + f(1)) != 0.

# Therefore we may apply f again to both sides to obtain that: f(f(y + f(1))) = 1 / (1 - y - f(1)) = f(1 - 1/y)


