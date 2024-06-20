
# 51 52 53 54 55 56 57 58 59 41 42 43 44 45 46 47 48 49 60

# x (9 higher than min(x, y), any amount below) y


# 50 39 38 37 36 35 33 33 32 31 49 48 47 46 45 44 43 42 41 (9 higher than 41) 51

# 1: 1
# 2: 02
# 3: 6175

# 1: 1
# = 1

# 2: 2 # 0 # 4 # 1 # 3
# = 5


# 3: 9 8 7 (# 13 # 4 2 6 3 5 # 16 # 4 2 6 3 5 # 15 #) 7 8 9
# 3: 9 8 7 130 4 2 6 3 5 150 14 12 16 13 15 140 17 18 19
# = (n - 1) + (f(1) + B1 + f(2) + B2 + f(2) + B1 + f(1)) + (n - 1)
# = 2 + 1 + 1 + 5 + 1 + 5 + 1 + 1 + 2
# = 19

# 4: (n - 1) + (f(1) + B1 + f(2) + B2 + f(3) + B3 + f(3) + B2 + f(2) + B1 + f(1)) + (n - 1)
# = 4 + 5 + 4 + 10 + 38

# dp = [0 for _ in range(12)]
# dp[0] = 0
# dp[1] = 1
# dp[2] = 5

# for i in range(3, 12):
#     # edges
#     dp[i] += 2 * (i - 1)
#     # barriers
#     dp[i] += (2 * (i - 1)) - 1

#     for j in range(1, i):
#         dp[i] += 2 * dp[j]

# print(dp)
# print(dp[10])

s, c, t = map(int, input().split())
a = input()
b = input()

stack = a if len(a) < len(b) else b

dists = {}

while stack:
    curr = stack.pop()
    