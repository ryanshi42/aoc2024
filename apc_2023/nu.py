

n, d, S = map(int, input().split())

x = 1
blah = []
while x <= d * 2:
    blah.append(x)
    x = x * 2

e = x
dp = [[[0 for _ in range(e)] for _ in range(d)] for _ in range(n + 1)]

# Max with taking at most d damage is this
for i in range(max(0, 1 - S), d):
    dp[0][i][1] = 1

# print(dp)
# i = 0
# for j in range(d):
#     for k in range(e):
#         dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k])

for i in range(1, n + 1):
    # for j in range(d):
    #     for k in range(e):

    #         # print(dp[i][j][k], dp[i][j - 1][k])
    #         dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k])
    for j in range(d):
        for k in blah:
            if k % 2 == 1 and k > 1:
                continue
            f = k // 2 if k != 1 else 1
            # print(k)

            # print(dp[i][j][k], dp[i][j - 1][k])
            # dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k])
            # print(dp[i][j][k])

            
            if (j - max(0, k * 2 - S) >= 0) and k * 2 < e:
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - max(0, f - S)][f] + k, dp[i - 1][j - max(0, k * 2 - S)][k * 2] + k)

            elif (j - max(0, f - S) >= 0):
                # print(f)
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - max(0, f - S)][f] + k)
                print(i, j, k, dp[i][j][k])


# print(dp)
print(max([dp[n - 1][d - 1][x] for x in blah]))
