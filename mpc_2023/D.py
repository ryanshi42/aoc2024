
import math


n = int(input())
queries = []
for i in range(n):
    q = map(int, input().split())
    queries.append(q)

for i in range(1, n + 1):
    t = False
    (A, B, C) = queries[i - 1]

    if B <= A:
        t = 2 * (C // B) - 1
    elif 2 * A <= B:
        t = C // A
    else:
        # buy a single and the rest should be doubles
        t = 1 + 2 * ((C - A) // B)
        # print(C, A, B, (C-A)//B)


    ans = max(0, t)
    print(f"Case #{i}: {ans}")
