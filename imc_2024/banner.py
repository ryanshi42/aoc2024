

# t = int(input())
# s = input()
# ans = 0
# for i in range(t):
#     for j in range(i + 2, t, 2):
#         if s[i] == "I" and s[(i + j) // 2] == "M" and s[j] == "C":
#             ans += 1

# print(ans)


(n, k) = tuple(map(int, input().split()))

s = input()
t = input()

cur = 1

ans = 0

for i in range(n):
    x = s[i]
    y = t[i]
    # print(x, y)

    # literally just add the number of strings made possibly at each index lol
    cur *= 2
    if x == "b":
        cur -= 1
    if y == "a":
        cur -= 1
    cur = min(cur,1000000000)
    ans += min(cur,k)
    # print(cur)
    # ans += dp
    # print(ans)

    # abb, baa, bab, bba, bbb

# ans = cur
print(ans)

