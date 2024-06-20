
n = int(input())
queries = []
for i in range(n):
    q = map(int, input().split())
    queries.append(q)

for i in range(1, n + 1):
    t = False
    (R, C, A, B) = queries[i - 1]

    t = True if R > C else False
    ans = "YES" if t else "NO"
    print(f"Case #{i}: {ans}")
