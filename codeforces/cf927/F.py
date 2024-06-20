
# t = int(input())

# for _ in range(t):
#     (n, m) = tuple(map(int, input().split()))
#     ivls = []
#     for _ in range(m):
#         ivls.append(list(map(int, input().split())))
#     ivls.sort(key=lambda x: x[0])
#     ivls.sort(key=lambda x: x[1])

#     ans = 0
#     prev = -1
#     # print(ivls)
#     curr = [0 for _ in range(n + 1)]
#     lmb = [n for _ in range(n + 1)]
#     for i in ivls:
#         curr[i[0] - 1] += 1
#         curr[i[1]] -= 1
#     ci = m - 1
#     for i in range(n, -1, -1):
#         if i != n:
#             lmb[i] = lmb[i + 1]
#         while ci >= 0 and i < ivls[ci][1]:
#             lmb[i] = min(lmb[i], ivls[ci][0])
#             ci -= 1
    
#     # print(lmb)

#     dp = []
#     v = 0
#     for i in curr:
#         v += i
#         dp.append(v)
#     # print(dp)
#     dp2 = [0 for _ in range(n)]
#     cm = 0
#     for i in range(n):
#         # print(lmb[i] - 1, dp2)
#         b = dp2[lmb[i] - 2] if lmb[i] - 2 >= 0 else 0
#         a = 0
#         if i != 0:
#             a = max(dp[i] + b, dp2[i - 1])
#         else:
#             a = dp[i]
#         dp2[i] = a
#     # print(dp2)
#     print(dp2[-1])


# n = int(input())

# for _ in range(n):

#     ans = []
#     x = int(input())
#     s = input()
#     temp = 0
#     for c in s:
#         temp += int(c)
#     for c in reversed(s): 
#         ans.append(temp)
#         temp -= int(c)
        
#     ans.append(temp)
#     while ans and ans[-1] == 0:
#         ans.pop()
#     # print(ans)
#     for i in range(len(ans)):
#         temp = ans[i]
#         ans[i] %= 10
#         j = i + 1
#         while temp // 10 > 0:
#             temp //= 10
#             if j < len(ans):
#                 ans[j] += temp % 10
#             else:
#                 ans.append(temp % 10)
#             j += 1
#     ans = [str(c) for c in ans]
#     # print(ans)
#     print("".join(reversed(ans)))

# 1*(0+1|01+)*0*(00111*(0+1|01+)*0*00111*(0+1|01+)*0*)*(0+1|01+)*0*
# 1*(0+1|01+)*0*(00111*(0+1|01+)*0*00111*(0+1|01+)*0*)*

# import heapq
# from collections import defaultdict
# v = int(input())

# for _ in range(v):
#     (n, m, H) = tuple(map(int, input().split()))
#     inits = list(map(int, input().split()))
#     changes = list(map(int, input().split()))
#     passages = defaultdict(lambda: set())
#     for _ in range(m):
#         (a, b) = tuple(map(int, input().split()))
#         a -= 1
#         b -= 1
#         passages[a].add(b)
#         passages[b].add(a)

#     h = []
#     heapq.heapify(h)
#     dists = [float('inf') for _ in range(n)]
#     dists[0] = 0
#     heapq.heappush(h, (0, 0))
#     while h:
#         (dist, node) = heapq.heappop(h)
#         # print("a", dist, node)
#         for i in range(n):
#             if i == node:
#                 continue
#             if i not in passages[node]:
#                 continue
#             now_i = (inits[i] + changes[i] * dist) % H
#             now_node = (inits[node] + changes[node] * dist) % H
#             seen = set()
#             curr = (now_i, now_node)
#             next = 0
#             while curr not in seen and curr[0] != curr[1]:
#                 next += 1
#                 seen.add(curr)
#                 curr = ((curr[0] + changes[i]) % H, (curr[1] + changes[node]) % H)
#             if curr in seen:
#                 continue
#             # print("next is", next, i)
#             assert((now_i + next * changes[i]) % H == (now_node + next * changes[node]) % H)
#             new_dist = dist + next
#             if new_dist < dists[i]:
#                 dists[i] = new_dist
#                 heapq.heappush(h, (new_dist, i))
#                 # print("pushed")

#     if dists[n - 1] == float('inf'):
#         print(-1)
#     else:
#         print(int(dists[n - 1]) + 1)


# from collections import deque, defaultdict, Counter

# t = int(input())


# for _ in range(t):
#     (n, m, a, b, c) = tuple(map(int, input().split()))
#     ps = list(map(int, input().split()))
#     edges = defaultdict(list)
#     for _ in range(m):
#         (x, y) = tuple(map(int, input().split()))
#         edges[x].append(y)
#         edges[y].append(x)

#     # print(edges)

#     ps.sort()

#     to_find = b
#     q = deque()
#     q.append((a, [a]))
#     path = [a]
#     found = False
#     while q and not found:
#         (curr, cp) = q.popleft()
#         for i in edges[curr]:
#             if i in cp:
#                 continue
#             temp = cp[:]
#             temp.append(i)
#             if i == to_find:
#                 path = temp
#                 found = True
#             q.append((i, temp))
#         # print(q)
        
#     assert(path != [])


#     to_find = c
#     q = deque()
#     q.append((b, [b]))
#     path2 = [b]
#     found = False
#     while q and not found:
#         (curr, cp) = q.popleft()
#         for i in edges[curr]:
#             if i in cp:
#                 continue
#             temp = cp[:]
#             temp.append(i)
#             if i == to_find:
#                 path2 = temp
#                 found = True
#             q.append((i, temp))

#     # print(path, path2)
#     used = []
#     for i in range(1, len(path)):
#         used.append(sorted((path[i], path[i - 1])))

#     for i in range(1, len(path2)):
#         used.append(sorted((path2[i], path2[i - 1])))

#     used = [tuple(u) for u in used]
#     # print(used)
#     c = Counter(used)
#     v = sorted(c.values(), reverse=True)
#     # print(v)
#     # print(ps)

#     ans = 0
#     for i in range(len(v)):
#         ans += v[i] * ps[i]
#     print(ans)

# from collections import Counter

# n = int(input())
# nums = list(map(int, input().split()))

# c = Counter(nums)
# # new = sorted(c.items())

# dp = [0 for _ in range(max(nums) + 1)]
# # dp represents the max deleting up to ak

# if len(dp) == 2:
#     print(sum(nums))
# else:

#     for i in range(1, max(nums) + 1):
#         dp[i] = max(dp[i - 1], dp[i - 2] + c[i] * i)

#     # print(dp)
#     print(dp[-1])

# import math
# from collections import Counter
# t = int(input())

# for _ in range(t):
#     (m, n2) = tuple(map(int, input().split()))
#     n = n2
#     if m % n != 0:
#         print(m)
#     else:
#         # Print the number of two's that divide n
#         i = 2
#         factors = []
#         while i * i <= n:
#             if n % i:
#                 i += 1
#             else:
#                 n //= i
#                 factors.append(i)
#         if n > 1:
#             factors.append(n)
#         c = Counter(factors)
#         # print(c)
#         ans = 1
#         for (k, v) in c.items():
#             # e.g. (3, 2)
#             contains = 0
#             n3 = m

#             while n3 % k == 0:
#                 contains += 1
#                 n3 = n3 / k
#                 if n3 % n2 != 0:
#                     ans = max(ans, n3) 
#             # contains -= (v - 1)
#             # print(n3, m, v, contains)
#             # ans = max(ans, m // (k ** contains))

#         print(int(ans))

                
        

        # tmp = [1]
        # found = False
        # for i in range(2, int(math.sqrt(m) + 1)):
        #     if m % i == 0:
        #         tmp.append(i)
        #         big = m // i
        #         if big % n != 0:
        #             found = True
        #             print(big)
        #             break
        
        # if not found:
        #     while tmp:
        #         big = tmp.pop()
        #         if big % n != 0:
        #             found = True
        #             print(big)
        #             break
            

# t = int(input())

# for _ in range(t):
#     n = int(input())
#     nums = list(map(int, input().split()))
#     pos = True if nums[0] > 0 else False

#     tmp = nums[0]
#     ans = []
#     for x in nums:
#         tp = True if x > 0 else False
#         if tp == pos:
#             tmp = max(tmp, x)
#         else:
#             ans.append(tmp)
#             pos = tp
#             tmp = x
#     ans.append(tmp)
#     print(sum(ans))
