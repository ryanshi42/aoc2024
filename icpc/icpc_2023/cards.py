
# def ic(o, j):
#     # print(o)
#     for k, elem in enumerate(o):
#         # print([x for x in o[:k] if x > elem])
#         # print([x for x in o[k+1:] if x > elem])
#         # print(j)
#         flip_left = 1
#         last = elem
#         for x in o[:k][::-1]:
#             # print(x, last)
#             if x > last:
#                 flip_left += 1
#                 last = x
        
#         flip_right = 1
#         last = elem
#         for x in o[k+1:]:
#             if x > last:
#                 flip_right += 1
#                 last = x
        
#         if flip_left > j or flip_right > j:
#             return False

#     # print("ic returned true")
#     return True

# import itertools

# f(4) = 3 2 1 B1 f(1) B2 f(2) B3 f(3) B4  f(3) B3 f(2)  B2 f(1)  B1 1 2 3



# dp(i, j) = dp(i, j - 1) + 1 + dp(i-1, j)




# for i in range(1, 4):
#     print("beginning turn " + str(i))

#     possible = True
    
#     for j in range(1, 100):
#         possible = False
        
#         # print(list(itertools.permutations(b, j)))
#         b = [i * 10 for i in range(0, j + 1)]
#         for comb in itertools.permutations(b, j):
#             # print(comb)
#             if ic(comb, i):
#                 possible = True
#                 print('This is possible')
#                 print(comb)
#                 break

#         if not possible:
#             print("Good effort, best answer is:")
#             print(j - 1)
#             break

dp = [[0 for _ in range(11)] for _ in range(11)]
for i in range(1, 11):
    for j in range(1, 11):
        dp[i][j] = dp[i][j-1] + 1 + dp[i-1][j]

print(dp)