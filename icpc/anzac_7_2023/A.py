

n = int(input())

ans = []

for i in range(n):
    a, b, c = map(int, input().split())

    dp = [1 for _ in range(c + 1)]
    
    d = 1
    powers = []
    while b ** d <= c:
        powers.append(b ** d)
        d += 1
    print(powers)

    # do powers first as the order matters (can only do all the threes first) => this guarantees the order
    for power in powers:
        for i in range(len(dp)):
            if i - power >= 0:
                dp[i] += dp[i - power]

    print(dp)

    ans.append((a, dp[c]))

for elem in ans:
    print(" ".join(map(str, elem)))