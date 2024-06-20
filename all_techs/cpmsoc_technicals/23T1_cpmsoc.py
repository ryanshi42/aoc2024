
# x = 21
# dp = [[0 for _ in range(x)] for _ in range(x)]
# dp[0][0] = 1

# for i in range(x):
#     for j in range(x):
#         if i + 1 < x and j + 2 < x:
#             dp[i + 1][j + 2] += dp[i][j]
#         if i + 2 < x and j + 2 < x:
#             dp[i + 2][j + 2] += dp[i][j]
#         if i + 2 < x and j + 1 < x:
#             dp[i + 2][j + 1] += dp[i][j]

# print(dp)
# print(dp[x-1][x-1])






# n = 5
# k = 3

# arr = [26, 17, 18, 5, 34]

# n, k = map(int, input().split())
# arr = [0 for _ in range(n)]

# for i in range(n):
#     arr[i] = int(input())

# window = 0
# best = -float('inf')

# for i in range(n):
#     if i < k - 1:
#         window += arr[i]
#     else:
#         window += arr[i]
#         best = max(window, best)
#         window -= arr[i - (k - 1)]
# print(best)
        


# n, k = 7, 7
# arr = [18, 3, 18, 1, 2, 18, 19]

# import bisect

# n, k = map(int, input().split())
# arr = [0 for _ in range(n)]

# for i in range(n):
#     arr[i] = int(input())

# arr.sort()


# best = k
# i = 0
# while i < n:
#     j = i + 1
#     prev = arr[i]
#     unique = 1
#     while j < n:
#         if arr[j] == prev:
#             j += 1
#         elif arr[j] < arr[i] + k:
#             unique += 1
#             j += 1
#             if j < n and arr[j] >= arr[i] + k:
#                 break
#         else:
#             break
#     window = max(k - unique, 0)

#     best = min(window, best)
#     i += 1
# print(best)
        

# import bisect

# # n, k = 7, 7
# # arr = [18, 3, 18, 1, 2, 18, 19]

# n, k = map(int, input().split())
# arr = [0 for _ in range(n)]
# unique = [0 for _ in range(n)]

# for i in range(n):
#     arr[i] = int(input())

# arr.sort()

# prev = -float('inf')
# for i, elem in enumerate(arr):
#     if i == 0:
#         unique[i] = 1
#     elif elem == arr[i - 1]:
#         unique[i] = unique[i - 1]
#     else:
#         unique[i] = unique[i - 1] + 1


# best = k
# i = 0

# while i < n:
#     next = bisect.bisect_right(arr, arr[i] + k - 1)
#     uniques = max(unique[next - 1] - unique[i] + 1, 1)
#     window = max(k - uniques, 0)

#     best = min(window, best)
#     i += 1
# print(best)


# n = int(input())
# specials = [int(x) for x in input().strip().split( )]

# # n = 6
# # specials = [6, 10, 13, 25, 4, 20]

# powers = []
# i = 1
# while i < 10e4:
#     powers.append(i)
#     i *= 2

# ans = -float('inf')
# # print(specials)


# for special in specials:
#     temp = set(specials)
#     temp.remove(special)
    
#     level = [special]
#     depth = 1
#     visited = set()
#     while level:
#         new_level = []
#         # print(level)
#         for curr in level:
#             if curr in temp:
#                 # print('hi', curr, special, temp)
#                 temp.remove(curr)
#                 if not temp:
#                     ans = max(ans, depth)
#                     break
#             if curr in visited:
#                 continue
#             visited.add(curr)
#             # print(curr)
#             for i in powers:
#                 if i >= curr and i - curr not in visited:
#                     new_level.append(i - curr)
#         level = new_level
#         depth += 1
# print(ans)


# from bisect import bisect_left
# from collections import defaultdict
# n = int(input())
# specials = [int(x) for x in input().strip().split( )]
# ss = set(specials)

# # n = 6
# # specials = [6, 10, 13, 25, 4, 20]

# powers = []
# i = 1
# while i < 10e9:
#     powers.append(i)
#     i *= 2

# ans = -float('inf')
# best_so_far = -float('inf')
# # print(specials)

# special_to_0 = defaultdict(lambda: defaultdict(lambda:0))

# for special in specials:
#     others = set(specials)
#     others.remove(special)
#     special_to_0[special][special] = 1
#     # e.g. 5
#     idx = bisect_left(powers, special)
#     top = powers[idx]
#     # e.g. 8
#     curr = top - special
#     while curr != 0:
#         if curr in others:
#             others.remove(curr)
#             ans = max(ans, len(special_to_0[special]) + 1)

#         # append 3
#         special_to_0[special][curr] = len(special_to_0[special]) + 1
#         # find 4
#         idx = bisect_left(powers, curr)
#         # e.g. 1 and then repeat
#         top = powers[idx]
#         curr = top - curr
#     special_to_0[special][curr] = len(special_to_0[special]) + 1

#     for j in others:
#         # print(special, x, len(special_to_0[special]) + len(special_to_0[x]) - 1)
#         for (key, value) in special_to_0[special].items():
#             if key in special_to_0[j]:
#                 # print(special_to_0[j][key], value, special, j, key)
#                 ans = max(ans, special_to_0[j][key] + value - 1)
#                 break


# # for i in specials:
# #     for j in specials:
# #         if i == j: 
# #             continue
# #         else:
# #             for (key, value) in special_to_0[i].items():
# #                 if key in special_to_0[j]:
# #                     ans = max(ans, special_to_0[j][key] + value - 1)
# #                     break
# #             for (key, value) in special_to_0[j].items():
# #                 if key in special_to_0[i]:
# #                     ans = max(ans, special_to_0[i][key] + value - 1)
# #                     break
# #                     # print(ans)
# #         # for elem in special_to_0

# # print(special_to_0.items())
    
# print(ans)


#  Python3 program for the above approach
from bisect import bisect_left

def minAbsDifference2(nums, goal: int) -> int:
    best = float('inf')
    # function that generates all possible sums of sebsequences
    def dfs(i,cur,arr,sums):
        if i==len(arr):
            sums.add(cur)
            return
        dfs(i+1,cur,arr,sums)
        dfs(i+1,cur+arr[i],arr,sums)
    
    sums1,sums2=set(),set()
    # generate all possible sums of the 1st and 2nd half 
    dfs(0,0,nums[:len(nums)//2],sums1)
    dfs(0,0,nums[len(nums)//2:],sums2)
    
    # sort the possible sums of the 2nd half
    s2=sorted(sums2)
    ans=10**10
    # for each possible sum of the 1st half, find the sum in the 2nd half
    # that gives a value closest to the goal using binary search
    for s in sums1:
        remain=goal-s
        # binary search for the value in s2 that's closest to the remaining value
        i2=bisect_left(s2,remain)
        if i2<len(s2):
            ans = abs(remain-s2[i2])
            best = min(best, goal + ans)
                

        if i2>0:
            ans = abs(remain-s2[i2 - 1])
            best = min(best, goal + ans)

    return best

def minAbsDifference3(nums, goal: int) -> int:
    nums.sort()
    best = float('inf')
    # function that generates all possible sums of sebsequences
    def dfs(i,cur,arr,sums):
        if i==len(arr):
            sums.add(cur)
            return
        dfs(i+1,cur,arr,sums)
        dfs(i+1,cur+arr[i],arr,sums)
    
    sums1,sums2,sums3=set(),set(),set()
    # generate all possible sums of the 1st and 2nd half 
    dfs(0,0,nums[:len(nums)//3],sums1)
    dfs(0,0,nums[len(nums)//3:2*len(nums)//3],sums2)
    dfs(0,0,nums[2*len(nums)//3:],sums3)
    print(sums1, sums2, sums3)
    
    # sort the possible sums of the 2nd half
    s3=sorted(sums3)
    ans=10**10
    # for each possible sum of the 1st half, find the sum in the 2nd half
    # that gives a value closest to the goal using binary search
    for s in sums1:
        for ss in sums2:
            remain=goal-ss-s
            # binary search for the value in s2 that's closest to the remaining value
            i3=bisect_left(s3,remain)
            print(ss + s, remain, i3)

            if i3<len(s3):
                ans = abs(remain-s3[i3])
                print("goal is, ans is")
                print(goal, ans)
                best = min(best, goal + ans)
            if i3>0:
                ans = abs(remain-s3[i3 - 1])
                print("goal is, ans is")
                print(goal, ans)
                best = min(best, goal + ans)

    return best
 
# Function to split the array into M
# groups such that maximum of the sum
# of all elements of all the groups
# is minimized
def findMinimumValue(arr, candies, bags):

    total = sum(arr)

    if bags == 2:
        return minAbsDifference2(arr, (sum(arr) + 1) // 2)
    elif bags == 3:
        return minAbsDifference3(arr, (sum(arr) + 2) // 3)
    else:
        raise OSError("candeeznuts")

    return total
    # N tasks
    # M bags
 
arr = [ 1, 7, 9, 2, 12, 3, 3 ]
N = len(arr)
K = 3
print(findMinimumValue(arr, N, K))
 
# Driver Code
n, k = map(int, input().split( ))
candeeznuts = []
for i in range(k):
    candeeznuts.append(int(input()))
print(findMinimumValue(candeeznuts, k, n))