


# 4
# 1 1
# 2 1
# 2 2
# 2 4
t = int(input())
t += 1
t = str(t)
while True:
    for i in range(0, len(t)):
        if i != 0 and t[i] == t[i - 1]:
            break
    else:
        break 
    if len(t) == 1:
        print(t)
        exit(0)
    else:
        ans = []
        for i in range(0, len(t)):
            if i != 0 and t[i] == t[i - 1]:
                x = int(t[i])
                x += 1
                b = True
                if x != 10:
                    ans.append(str(x))
                    b = True
                else:
                    for j in range(len(ans) - 1, -1, -1):
                        y = int(ans[j])
                        y += 1
                        if y != 10:
                            ans[j] = str(y)
                            break
                        else:
                            ans[j] = "0"
                    else:
                        ans.insert(0, "1")
                    ans.append("1")
                for j in range(i + 1, len(t)):
                    if b:
                        ans.append("0")
                    else:
                        ans.append("1")
                    b = False if b else True
                break
            else:
                ans.append(t[i])
    t = ans

print("".join(ans))



# arr = []
# tops = [0 for _ in range(7)]
# grid = []

# for _ in range(t):
#     n, m = map(int, input().split())
#     if n == 1:
#         sdf
#     elif n == 2:



