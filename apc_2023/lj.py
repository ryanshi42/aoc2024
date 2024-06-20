# 5 3
# 2 4 5
# 1 0 5
# 2 3 3
# 0 2 4


N, K = map(int, input().split())

from collections import defaultdict, deque
cs = defaultdict(lambda : list())
parent = defaultdict(lambda: 0)
dist = defaultdict(lambda : 0)

depth = defaultdict(lambda : list())

conns = defaultdict(lambda : list())

for _ in range(N - 1):
    s, t, l = map(int, input().split())
    dist[(s, t)] = l
    dist[(t, s)] = l
    conns[s].append(t)
    conns[t].append(s)

temp = set()

queue = deque([(0, -1)])
md = 0

visited = set()

while queue:
    (curr, dep) = queue.popleft()
    depth[dep].append(curr)

    visited.add(curr)

    # for (x, y) in dist:
    #     if (x, y) in temp:
    #         continue
    #     if x == curr:
    #         cs[curr].append(y)
    #         parent[y] = curr
    #         dist[(curr, y)] = dist[(x, y)]
    #         temp.add((x, y))
    #     elif y == curr:
    #         cs[curr].append(x)
    #         parent[x] = curr
    #         dist[(curr, x)] = dist[(x, y)]
    #         temp.add((x, y))

    for conn in conns[curr]:
        if conn in visited:
            continue
        parent[conn] = curr
        cs[curr].append(conn)

    for child in cs[curr]:
        queue.append((child, dep + 1))



    md = max(md, dep)
# print(conns)
# print(cs)

# print(depth)

ans = 0
pb = defaultdict(lambda : 0)
for i in range(md, -1, -1):
    all_depths = depth[i]
    # print(all_depths)
    # get all depths
    seen = set()
    for x in (all_depths):
        # print(parent[x], x, dist[(parent[x], x)])
        if dist[(parent[x], x)] >= K: 
            ans += dist[(parent[x], x)] // K
        pb[parent[x]] = max(pb[parent[x]], dist[(parent[x], x)] % K)
        seen.add(parent[x])
    for s in seen:
        dist[(parent[s], s)] += pb[s]
        # print("hi", parent[s], s, pb[s])

print(ans)