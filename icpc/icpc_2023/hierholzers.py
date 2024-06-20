from collections import defaultdict
import sys

n, k = map(int, input().split())


graph = defaultdict(lambda: [])
in_vertices = defaultdict(lambda: 0)
out_vertices = defaultdict(lambda: 0)
vertices = set()

for _ in range(n - k):
    x, y = input().split()
    graph[x].append(y)
    in_vertices[y] += 1
    out_vertices[x] += 1
    vertices.add(x)
    vertices.add(y)

# either two have odd degree (path) or all have even degree (circuit)
odds = 0
for vertex in vertices:
    # print()
    if (out_vertices[vertex] - in_vertices[vertex]) % 2 == 1:
        odds += 1

# print(odds)

# if odds != 2:
#     print("WHAT?")
#     sys.exit(1)

start = None
for vertex in vertices:
    if (out_vertices[vertex] - in_vertices[vertex]) % 2 == 1 and out_vertices[vertex] > in_vertices[vertex]:
        start = vertex
        break
    else:
        start = vertex

# print(out_vertices, in_vertices, start)

if not start:
    print("HUH?")
    sys.exit(1)

path = []

def dfs(v):

    while out_vertices[v] > 0:
        out_vertices[v] -= 1
        # print(graph[v], out_vertices[v])
        dfs(graph[v][out_vertices[v]])
    path.append(v)


dfs(start)

path = path[::-1]
# print(path)

print("".join([a[0] for a in path] + [path[-1][1:]]))



# 6 2
# CA AC
# CG GT
# AC CA
# AC CG