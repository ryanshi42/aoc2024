
n, k = map(int, input().split())

lines = []
bsf = 0
cnt = 0

# 

ans = (n + k) * 10
for _ in range(n):
    line = input()
    lines.append(line + "X")

    # for i, elem in enumerate(line):
    #     if elem == "X":
    #         continue
    #     if i <= bsf:
    #         continue
    #     else:
    #         bsf = i
    #         cnt +=1 
    #         break

lines.append("X" * (k + 1))

from functools import lru_cache
import math

def isO(x, y):
    if x < 0 or y < 0:
        return False
    if x >= len(lines) or y >= len(lines[0]):
        return False
    return lines[x][y] == 'O'

dpf = [[0 for _ in range(n + 1)] for _ in range(k + 1)]
dpt = [[0 for _ in range(n + 1)] for _ in range(k + 1)]


import math

# print(cnt)
# print(ans)
print(round(ans - cnt * (10) + cnt * 5 * math.pi / 2, 10))
