(coins, rows) = tuple(map(int, input().split()))

runes = []
for _ in range(rows):
    runes.append(list(map(int, input().split())))

def dfs(runes, used, rowset, nr, nc):

    # print(runes, used, rowset, nr, nc)

    # Row to pick
    tr = -1
    for (xr, [a, b, c]) in enumerate(runes):
        if a not in used and b not in used and c not in used:
            tr = xr
            break
    if tr == -1:
        return True

    # Had a stupid bug with overwriting variables... ugh
    for i in range(3):
        tc = 0
        if runes[tr][i] != 0 and runes[tr][i] not in used and -runes[tr][i] not in used:
            tc = runes[tr][i]
        else:
            continue

        used.add(tc)
        # for (xr, [a, b, c]) in enumerate(runes):
        #     if tc == a or tc == b or tc == c:
        #         rowset[xr] += 1

        if dfs(runes, used, rowset, nr, nc):
            return True

        used.remove(tc)
        # for (xr, [a, b, c]) in enumerate(runes):
        #     if tc == a or tc == b or tc == c:
        #         rowset[xr] -= 1

    return False

from collections import defaultdict
rowset = defaultdict(lambda: 0)
used = set()
res = dfs(runes, used, rowset, rows, coins)

if not res:
    print("Doomed")
else:
    ans = []
    for i in range(1, coins + 1):
        if -i in used:
            ans.append("T")
        else:
            ans.append("H")
    print(" ".join(ans))

