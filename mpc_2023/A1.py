
n = int(input())
queries = []
for i in range(n):
    S, D, K = map(int, input().split())
    queries.append((S, D, K))

for i in range(1, n + 1):
    t = False
    (S, D, K) = queries[i - 1]
    buns = 2 * (S + D)
    patties = S + 2 * D

    if buns >= K + 1 and patties >= K:
        t = True

    ans = "YES" if t else "NO"
    print(f"Case #{i}: {ans}")
