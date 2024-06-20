

n = int(input())

# x = int("33", 16)
# print(x)

ans = []

memo = dict()

def p(n,k):
    if k > (n-1)/2:
        return p(n, n - k - 1)
    elif n - k == 1:
        return 1
    elif k == 0:
        return 1
    elif (n,k) in memo:
        return memo[n,k]
    
    # k + 1 spots to preserve inversions (at end or at an inversion)
    # n - k spots to insert an additional inversion (not at end)
    memo[n,k] = (k + 1) * p(n - 1, k) + (n - k) * p(n-1,k-1)
    return memo[n,k]

for i in range(n):
    j, n, v = input().split()
    n,v = int(n),int(v)
    print(j,p(n,v) % 1001113)
    # print(memo % 1001113)