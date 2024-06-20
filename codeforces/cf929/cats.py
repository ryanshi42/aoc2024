t = int(input())
 
res = []
 
for _ in range(t):
    n, m = tuple(map(int, input().split()))
 
    intervals = []
 
    for _ in range(m):
        intervals.append(tuple(map(int, input().split())))
 
    flags = [0 for _ in range(n + 1)]
 
    for start, end in intervals:
        flags[start] += 1
        if end != n:
            flags[end + 1] -= 1
 
    count = 0
    for i, f in enumerate(flags):
        count += f
        flags[i] = count
 
    intervals.sort(key=lambda x: (x[1], x[0]))

    # print(intervals)
    # print(flags)
 
    filtered = [intervals[0]] + [intervals[i] for i in range(1, m) if intervals[i][1] > intervals[i - 1][1]]
    leftmost = [-1 for _ in range(n + 1)]
 
    minimum = filtered[-1][0]
    # print(filtered)
 
    for i in range(len(filtered) - 2, -1, -1):
        for j in range(max(filtered[i][1] + 1, minimum), filtered[i + 1][1] + 1):
            # print("j=", j)
            # print(minimum, filtered[i], filtered[i + 1], leftmost)
            leftmost[j] = minimum
            # assert(minimum <= j)
 
        if filtered[i][0] < minimum:
            minimum = filtered[i][0]
    
    for i in range(minimum, filtered[0][1] + 1):
        leftmost[i] = minimum
    # print(leftmost)
 
    dp = [0]
 
    for i in range(1, n + 1):
        if leftmost[i] == -1:
            dp.append(dp[-1])
        else:
            dp.append(max(dp[-1], dp[leftmost[i] - 1] + flags[i]))
    
    res.append(dp[-1])
 
for r in res:
    print(r)