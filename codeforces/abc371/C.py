def solve(self, nums):
    count = 0
    ans = 0
    for i in range(2, len(nums)):
        if nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]:
            count += 1
        else:
            ans += (count * (count + 1)) // 2
            count = 0
    if count:
        ans += (count * (count + 1)) // 2
    return ans

