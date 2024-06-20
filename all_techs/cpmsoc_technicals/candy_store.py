#  Python3 program for the above approach
from bisect import bisect_left

dp = {}

def highest_min_2(nums, goal: int) -> int:
    # do stuff here
    nums.sort()
    if tuple(nums) in dp:
        return dp[tuple(nums)][0]
    
    ans = 0
    def dfs(left, cur):
        nonlocal ans
        if ans < cur <= goal:
            ans = cur
        # elif cur > goal:
            # this line breaks a few first test cases... hmm, I wonder why.
        #     return
        if left == len(nums):
            return
        dfs(left + 1, cur)
        dfs(left + 1, cur + nums[left])
    dfs(0, 0)
    dp[tuple(nums)] = (ans, sum(nums) - ans)
    return ans

def highest_min_3(nums, goal: int) -> int:
    # do stuff here
    sn = sum(nums)
    
    best_min = 0
    best = float('inf')
    def dfs(left, cur, unused):
        nonlocal best_min
        nonlocal best

        # print(left, cur, unused)
        # solved the second TLE
        if best_min <= cur <= goal and cur > goal // 2:
            new_arr = nums[left:] + unused

            total = sum(new_arr)
            # means there's actually a chance that we could do better
            if total // 2 <= best:
                rem_min = highest_min_2(new_arr, (total) // 2)
                rem_max = total - rem_min
                # print(cur, new_arr, nums[left:], unused, rem_max, rem_min)
                # best max of remaining array
                # if total - highest_min_2(new_arr, (total) // 2) <= cur:
                    # print(cur)
                    # best min
                best_min = min(rem_min, cur)
                best = min(best, max(rem_min, cur, rem_max))
                if best == goal:
                    return best
                # print(best, cur, total - highest_min_2(new_arr, (total) // 2) , new_arr, nums[left + 1:], unused, )
            # elif cur > goal:
            #     # this line breaks the first test case... hmm, I wonder why.
            #     return
        if left == len(nums):
            return
        dfs(left + 1, cur, unused + [nums[left]])
        dfs(left + 1, cur + nums[left], unused[:])
    dfs(0, 0, [])
    # return best_min
    # print(dp)
    return best
 
# Function to split the array into M
# groups such that maximum of the sum
# of all elements of all the groups
# is minimized
def findMinimumValue(arr, candies, bags):

    total = sum(arr)

    if bags == 2:
        return total - highest_min_2(arr, sum(arr) // 2)
    elif bags == 3:
        return highest_min_3(arr, (sum(arr) + 2) // 3)
    else:
        raise OSError("candeeznuts")

    return total
    # N tasks
    # M bags
 
# arr = [ 1, 7, 9, 2, 12, 3, 3 ]
# N = len(arr)
# K = 3
# print(findMinimumValue(arr, N, K))
 
# Driver Code
n, k = map(int, input().split( ))
candeeznuts = []
for i in range(k):
    candeeznuts.append(int(input()))
print(findMinimumValue(candeeznuts, k, n))