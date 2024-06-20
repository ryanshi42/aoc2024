
# t = int(input())

# for _ in range(t):
#     n = int(input())
#     a = list(map(int, input().split()))
#     a.sort()
#     a = [abs(b) for b in a]
#     print(sum(a))


# t = int(input())

# for _ in range(t):
#     n = int(input())
#     a = list(map(int, input().split()))
#     x = sum(a)
#     if x % 3 == 0:
#         print(0)
#     else:
#         for b in a:
#             if b % 3 == x % 3:
#                 print(1)
#                 break
#         else:
#             print(3 - x % 3)

# t = int(input())

# for _ in range(t):
#     (a, b, l) = tuple(map(int, input().split()))
#     ca = 0
#     l2 = l
#     while l2 % a == 0:
#         l2 /= a
#         ca += 1
    
#     cb = 0
#     l2 = l
#     while l2 % b == 0:
#         l2 /= b
#         cb += 1

#     x = set()

#     for i in range(ca + 1):
#         for j in range(cb + 1):
#             if l % (a ** i * b ** j) == 0:
#                 # print(i, j, l / (a ** i * b ** j))
#                 x.add(l / (a ** i * b ** j))

#     print(len(x))
#     # print((ca + 1) * (cb + 1))



# t = int(input())

# for _ in range(t):
#     n = int(input())
#     a = list(map(int, input().split()))
#     q = int(input())
#     dp = [a[0]]
#     for i in range(1, n):
#         dp.append(dp[i - 1] + a[i])
#     ans = []
#     for _ in range(q):
#         (l, u) = tuple(map(int, input().split()))
#         # print(a)
#         # print(dp)

#         minus = dp[l - 2] if l - 2 >= 0 else 0
#         x = l - 1
#         y = n - 1
#         while x < y:
#             mid = x + (y - x) // 2
#             cs = dp[mid] - minus

#             cv = dp[mid - 1] - minus
#             if mid < l:
#                 cv = -float('inf')

#             if mid == n - 1:
#                 break
#             ct = dp[mid + 1] - minus
#             # print(mid, cv, cs, ct)
#             z1 = -float('inf') if cv == -float('inf') else cv * u - ((cv * (cv - 1)) // 2)  
#             z2 = cs * u - ((cs * (cs - 1)) // 2)
#             z3 = ct * u - ((ct * (ct - 1)) // 2)
#             if cv == -float('inf'):
#                 if z2 == z3:
#                     x = mid
#                     break
#                 if z2 < z3:
#                     x = mid + 1
#                     break
#                 if z2 > z3:
#                     x = mid
#                     break


#             # print()
#             # print(cv * u - ((cv * (cv - 1)) // 2))
#             # print(cs * u - ((cs * (cs - 1)) // 2))
#             # print(ct * u - ((ct * (ct - 1)) // 2))
#             # print()
#             if cs * u - ((cs * (cs - 1)) // 2) == ct * u - ((ct * (ct - 1)) // 2):
#                 x = mid
#                 break
#             elif z1 == cs * u - ((cs * (cs - 1)) // 2):
#                 # THIS WAS THE STUPID BUG
#                 x = mid - 1
#                 break
#             elif z1 < cs * u - ((cs * (cs - 1)) // 2) and cs * u - ((cs * (cs - 1)) // 2) > ct * u - ((ct * (ct - 1)) // 2):
#                 x = mid
#                 break
#             elif z1 < cs * u - ((cs * (cs - 1)) // 2) and cs * u - ((cs * (cs - 1)) // 2) < ct * u - ((ct * (ct - 1)) // 2):
#                 x = mid + 1
#             else:
#                 y = mid
#         ans.append(str(x + 1))
        
#     print(" ".join(ans))

# t = int(input())

# for _ in range(t):
#     n = int(input())
#     a = list(map(int, input().split()))
#     a.sort()
#     if a[0] != a[1]:
#         print("YES")
#     else:
#         f = False
#         for i in range(2, n):
#             if a[i] % a[0] != 0:
#                 f = True
#         if f:
#             print("YES")
#         else:
#             print("NO")
# 
# 

# from collections import deque, defaultdict
# t = int(input())

# for _ in range(t):
#     (m, n) = tuple(map(int, input().split()))
#     grid = ""
#     for _ in range(m):
#         row = input().split()
#         grid += ("".join(row))

#     q = deque()
#     q.append((0, 0, 0))
#     x = -1
#     # rocks = defaultdict(set)
#     # for i in range(m):
#     #     for j in range(n):
#     #         if grid[i][j]:
#     #             rocks[j].add(i)

#     seen = set()
#     while q:
#         (cx, cy, ct) = q.popleft()
#         if (cx, cy, ct % m) in seen:
#             continue
#         seen.add((cx, cy, ct % m))
#         if cx == n - 1 and cy == m - 1:
#             x = ct
#             break
#         poss = [(cx + 1, cy), (cx, (cy + 1) % m), (cx, (cy - 1) if cy > 0 else m - 1)]
#         for (px, py) in poss:
#             if px >= n:
#                 continue
#             rp = (py + ct) % m
#             rp2 = (rp + 1) % m
#             # print(px, py, rp, rp2)
#             # print(rocks)
#             # print(len(grid))
#             if (py == (cy + 1) % m and grid[rp * n + px] == "1") or grid[rp2 * n + px] == "1":
#                 continue
#             q.append((px, py, ct + 1))
#     print(x)
        
# a(baba)a

# (m, n) = input().split()
# n = int(n)
# arr = []

# if n == 1:
#     print(m)
#     exit(0)

# for i in str(m):
#     iz = int(i)
#     if not arr:
#         arr.append([1, iz])
#     else:
#         if iz == arr[-1][1]:
#             arr[-1][0] += 1
#         else:
#             arr.append([1, iz])


# for _ in range(n - 2):
#     print(arr)
#     new_arr = []
#     for (j, blah) in enumerate(arr):
#         i = blah[0]
#         x = blah[1]
#         if i == x:
#             i = 2
#             aa = [2, x]
#             new_arr.append(aa)
#         else:
#             aa = [1, i]
#             new_arr.append(aa)
#             if j + 1 < len(arr) and arr[j + 1][1] == x:
#                 arr[j + 1][0] += 1
#             else:
#                 bb = [1, x]
#                 new_arr.append(bb)
#             # e.g. 13 -> 1 1 1 3
#             # e.g. 22 -> 2 1 1 -> 1 2 2 1 -> 1 1 2 2 1 1
#             # e.g. 31 -> 4 2 -> 1 4 1 2

#     arr = new_arr

# for blah in arr:
#     print(str(blah[0]) + str(blah[1]), end="")
# print()

# (r, c, a, b) = tuple(map(int, input().split()))

# signature = []
# for i in range(r):
#     signature.append(input())

# artwork = []
# for i in range(a):
#     artwork.append(input())

# for i in range(a - r + 1):
#     for j in range(b - c + 1):
#         found = True
#         for k in range(r):
#             for l in range(c):
#                 # print(i + k)
#                 if signature[k][l] != artwork[i + k][j + l]:
#                     found = False
#                     break
#             if not found:
#                 break
#         if found:
#             print("Genuine")
#             exit(0)

# if found:
#     print("Genuine")
# else:
#     print("Forgery")

# (m, n) = input().split()
# n = int(n)
# arr = []
# new_arr = []

# if n == 1:
#     print(m)
#     exit(0)

# new_arr = []
# for i in str(m):

#     iz = int(i)
#     if not new_arr:
#         new_arr.append([1, iz])
#     else:
#         if iz == new_arr[-1][1]:
#             new_arr[-1][0] += 1
#         else:
#             new_arr.append([1, iz])

# for blah in new_arr:
#     arr.append(blah[0])
#     arr.append(blah[1])

# # print(arr)

# for _ in range(n - 2):
#     new_arr = []
#     for i in arr:
#         iz = int(i)
#         if not new_arr:
#             new_arr.append([1, iz])
#         else:
#             if iz == new_arr[-1][1]:
#                 new_arr[-1][0] += 1
#             else:
#                 new_arr.append([1, iz])
#     arr = []
#     for blah in new_arr:
#         arr.append(blah[0])
#         arr.append(blah[1])
#     # print("".join([str(s) for s in arr]))


# print("".join([str(s) for s in arr]))
# print(len(arr))


# n = int(input())
# arr = list(map(int, input().split()))
# best = 0
# high = -1
# for a in arr:
#     # print(a, high, best)
#     if a == high + 1:
#         high = a
#     elif a < high:
#         best += high - a
#     else:
#         # a must be a lot higher than high...
#         for i in range(high + 1, a):
#             best += i
#         high = a

# print(best)



# (m, n) = input().split()
# n = int(n)
# arr = [int(c) for c in m]
# new_arr = []

# if n == 1:
#     print(m)
#     exit(0)

# for _ in range(n - 1):
#     new_arr = []
#     i = 0
#     while i < len(arr):
#         count = 1
#         iz = arr[i]
#         i += 1
#         # print(i, len(arr))
#         while i < len(arr) and arr[i] == iz:
#             count += 1
#             i += 1
#         new_arr.append(count)
#         new_arr.append(iz)
#     arr = new_arr



# print("".join([str(s) for s in arr]))
# print(len(arr))


# n = int(input())
# arr = list(map(int, input().split()))

# dp = [0 for _ in range(n)]
# best = 0
# high = -1
# s = 0

# ca = 0
# for i, a in enumerate(arr):
#     ca += a
#     if a > high:
#         # print(a)
#         j = i
#         tmp = a
#         while dp[j] != tmp:
#             # print(j, tmp, dp)
#             dp[j] = tmp
#             tmp -= 1
#             j -= 1
#     else:
#         dp[i] = dp[i - 1]

#     high = dp[i]
    
#     # if a == high + 1:
#     #     high = a
#     # elif a < high:
#     #     best += high - a
#     # else:
#     #     # a must be a lot higher than high...
#     #     c = 1
#     #     for i in range(high + 1, a):
#     #         best += c
#     #         c += 1
#     #     high = a
#     # print(a, high, best)

# print(sum(dp) - ca)

# n = int(input())
# arr = list(map(int, input().split()))

# dp = [0 for _ in range(n + 1)]
# high = max(arr) + 1
# ans = 0

# # Basically do a two way DP to find the max needed from left and from right...
# for i in range(1, n + 1):
#     dp[i] = max(dp[i - 1], arr[i - 1] + 1)

# # print(dp)

# for i in range(n - 1, -1, -1):
#     dp[i] = max(dp[i], dp[i + 1] - 1)

# # print(dp)

# for i in range(1, n + 1):
#     ans += dp[i] - arr[i - 1] - 1

# print(ans)





# (a, b, c, d) = tuple(map(int, input().split()))

# if d == 0 and a == 0:
#     if b == 1 and c == 0:
#         print("01")
#         exit(0)
#     if c == 1 and b == 0:
#         print("10")
#         exit(0)
#     else:
#         print("impossible")
#         exit(0)


# elif a == 0:
#     # at most one 0
#     td = 0 
#     ca = 0
#     curr = 1
#     while ca < d:
#         td += 1
#         ca += curr
#         curr += 1

#     if ca > d:
#         print("impossible")
#         exit(0)

#     if b == c == 0:
#         print("1" * (td + 1))
#         exit(0)
#     elif b + c != (td + 1):
#         print("impossible")
#         exit(0)
#     else:
#         print(f"{'1' * c}0{'1' * b}")
#         exit(0)


# elif d == 0:
#     # at most one 1
#     ta = 0 
#     ca = 0
#     curr = 1
#     while ca < a:
#         ta += 1
#         ca += curr
#         curr += 1

#     if ca > a:
#         print("impossible")
#         exit(0)

#     if b == c == 0:
#         print("0" * (ta + 1))
#         exit(0)
#     elif b + c != (ta + 1):
#         print("impossible")
#         exit(0)
#     else:
#         print(f"{'0' * b}1{'0' * c}")
#         exit(0)


# else:
#     ta = 0
#     ca = 0
#     curr = 1
#     while ca < a:
#         ta += 1
#         ca += curr
#         curr += 1

#     if ca > a:
#         print("impossible")
#         exit(0)

#     td = 0 
#     ca = 0
#     curr = 1
#     while ca < d:
#         td += 1
#         ca += curr
#         curr += 1

#     if ca > d:
#         print("impossible")
#         exit(0)

#     if b + c != (ta + 1) * (td + 1):
#         print("impossible")
#         exit(0)

#     td = 1

# T = int(input())

# for _ in range(T):
#     n = int(input())
#     a = list(map(int, input().split()))
#     a.sort()
    
#     ans = 0
#     mod = 1e9 + 7
#     P = 0
#     Q = 0
#     for (i, num) in enumerate(a):
#         P = (P + num * (2 ** (n - 1 - i))) % mod
#         Q = (Q + num * (2 ** i)) % mod
#     print(int((Q + mod - P) % mod))


# Matrix multiplication :skull:
# (n, m) = tuple(map(int, input().split()))

# dp = [0 for _ in range(n + 1)]
# dp[0] = 1

# mod = int(1e7 + 9)
# for i in range(1, n + 1):
#     dp[i] = dp[i - 1]
#     if i >= m:
#         dp[i] += dp[i - m]
#     dp[i] %= mod

# # print(dp)
# print(dp[-1])


# (n, m) = tuple(map(int, input().split()))

# import math

# T = int(input())
# a = list(map(int, input().split()))

# a1 = []
# a2 = []
# for j in range(T):

#     found = False
#     i = 2
#     factors = []
#     n = a[j]
#     while i * i <= n:
#         if n % i:
#             i += 1
#         else:
#             n //= i
#             if factors and factors[-1] == i:
#                 continue
#             factors.append(i)
#             if len(factors) == 2:
#                 break
#     if n > 1 and len(factors) == 1 and factors[-1] != n:
#         factors.append(n)

#     if len(factors) == 2:
#         a1.append(str(factors[0]))
#         a2.append(str(factors[1]))

#     else:
#         a1.append(str(-1))
#         a2.append(str(-1))

# print(" ".join(a1))
# print(" ".join(a2))


# Very nice proof here... about primes and divisibility, take ALL the primes
# ALSO BE CAREFUL, there is obviously a much easier way to do things, just keep track of the smallest prime each time...

# import sys
# T = int(sys.stdin.readline())
# # a = list(map(int, sys.stdin.readline().split()))

# n = int(1e7)
# # ps = []
# prime = [-1 for i in range(n+1)]

# # eratosthenes
# def SieveOfEratosthenes(n) :

#     # Create a boolean array
#     # "prime[0..n]" and initialize
#     #  all entries it as true.
#     # A value in prime[i] will
#     # finally be false if i is
#     # Not a prime, else true.

#     p = 2
#     while (p * p <= n):
 
#         # If prime[p] is not
#         # changed, then it is a prime
#         if (prime[p] == -1):
 
#             # Update all multiples of p
#             for i in range(p * p, n+1, p):
#                 prime[i] = p
#         p += 1
 
#     # # Print all prime numbers
#     # for p in range(2, n+1):
#     #     if prime[p] > 0:
#     #         ps.append(p)

# SieveOfEratosthenes(n)

# a1 = []
# a2 = []
# for j in map(int, input().split()):

#     n = j
    
#     f1 = None
#     f2 = None 

#     found = False
#     p = prime[j]
#     # print(ps[0:10])
#     # print(p)
#     if p == -1:
#         pass
#     elif n % p == 0:
#         while n % p == 0:
#             n //= p
#         if n != 1:
#             f1 = p
#             f2 = n
#             a1.append(f1)
#             a2.append(f2)
#             found = True
#     if not found:
#         a1.append(-1)
#         a2.append(-1)

# print(*a1)
# print(*a2)

# # # # print(ps)


# n = int(input())
# prime = [-1]*(10**7+1)
# for i in range(2,10**7+1):
# 	if prime[i]==-1:
# 		prime[i]=i
# 		for j in range(i*i,10**7+1,i):
# 			if prime[j]==-1:
# 				prime[j]=i
# b=[]
# c=[]
# for i in map(int,input().split()):
# 	j=i
# 	d=prime[j]
# 	while j%d==0:
# 		j//=d
# 	if j==1:
# 		b+=[-1]
# 		c+=[-1]
# 	else:
# 		b+=[j]
# 		c+=[d]
# print(*b)
# print(*c)