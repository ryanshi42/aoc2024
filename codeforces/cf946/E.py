

t = int(input())

# month, money, happiness
# def solve(mi, money, hap, h, m, x, seen):
#     if mi == len(h):
#         return hap
#     else:
#         # if (mi, money, hap) in seen:
#         #     return seen[(mi, money, hap)]
#         (hi, hj) = h[mi]
#         b = 0
#         if money >= hi:
#             b = solve(mi + 1, money + x - hi, hap + hj, h, m, x, seen)
#         ans = max(solve(mi + 1, money + x, hap, h, m, x, seen), b)
#         # seen[(mi, money, hap)] = ans
#         return ans


for _ in range(t):
    (m, x) = tuple(map(int, input().split()))

    h = []
    for i in range(m):
        (a, b) = tuple(map(int, input().split()))
        h.append((a, b))
    # seen = {}
    # # print("ans")
    # print(solve(0, 0, 0, h, m, x, seen))

    for i in range(m):
        for w in range(1000 * m):
