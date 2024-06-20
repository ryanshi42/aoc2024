arr = [x for x in range(1, 30)]
print(arr)
m = 3

def subset_sum(arr, m):
    dp = [1, 0, 0]
    for this_len in range(1, len(arr) + 1):
        temp_0 = 0
        temp_1 = 0
        temp_2 = 0
        if arr[this_len - 1] % 3 == 0:
            dp[0] += dp[0] 
            dp[1] += dp[1] 
            dp[2] += dp[2] 
        if arr[this_len - 1] % 3 == 1:
            temp_1 = dp[0] 
            temp_2 = dp[1] 
            temp_0 += dp[2] 
        if arr[this_len - 1] % 3 == 2:
            temp_2 = dp[0] 
            temp_0 = dp[1] 
            temp_1 = dp[2] 
            
        dp[0] += temp_0
        dp[1] += temp_1
        dp[2] += temp_2

        # ans = 0
        # def dfs(i, end, arr, curr=[]):
        #     if i == end:
        #         if sum(curr) % 3 == 0:
        #             nonlocal ans
        #             ans += 1
        #         return
        #     dfs(i + 1, end, arr, curr + [arr[i]])
        #     dfs(i + 1, end, arr, curr)

        # dfs(0, this_len, arr)
        print(f"answer for length {this_len} is {dp[0]}")

subset_sum(arr, m)