from bisect import bisect_left
from collections import defaultdict
n = int(input())
specials = [int(x) for x in input().strip().split( )]
ss = set(specials)

# n = 6
# specials = [6, 10, 13, 25, 4, 20]

powers = []
i = 1
while i < 10e9:
    powers.append(i)
    i *= 2

ans = -float('inf')
best_so_far = -float('inf')
# print(specials)

special_to_0 = defaultdict(lambda: defaultdict(lambda:0))

# N operation
for special in specials:
    special_to_0[special][special] = 1
    # e.g. 5
    idx = bisect_left(powers, special)
    top = powers[idx]
    # e.g. 8
    curr = top - special
    while curr != 0:
        # append 3
        special_to_0[special][curr] = len(special_to_0[special]) + 1
        # find 4
        idx = bisect_left(powers, curr)
        # e.g. 1 and then repeat
        top = powers[idx]
        curr = top - curr
    special_to_0[special][curr] = len(special_to_0[special]) + 1

# NOW must find the max LCA of this tree

# Greedy Approach 1 ////////////////////////////////
# GENIUS SOLUTION TO FIND DISTANCE BETWEEN TWO ELEMENTS

# N^2 operation
node_x = specials[0]
node_y = None
others = set(specials)
others.remove(node_x)
max_dist_from_x = -float('inf')
for j in others:
    # print(special, x, len(special_to_0[special]) + len(special_to_0[x]) - 1)
    for (key, value) in special_to_0[node_x].items():
        # print(key, value, j, others, node_y, special_to_0[j][key] + value - 1)

        if key in special_to_0[j]:
            
            # print(special_to_0[j][key], value, special, j, key)
            if special_to_0[j][key] + value - 1 >= max_dist_from_x:
                max_dist_from_x = special_to_0[j][key] + value - 1
                node_y = j
            break
ans = max(ans, max_dist_from_x)
# print(node_y, ans)

others = set(specials)
others.remove(node_y)
max_dist_from_y = -float('inf')
node_z = None

for j in others:
    # print(special, x, len(special_to_0[special]) + len(special_to_0[x]) - 1)
    for (key, value) in special_to_0[node_y].items():
        # print(key, value, j, others)
        if key in special_to_0[j]:
            # print(special_to_0[j][key], value, special, j, key)
            if special_to_0[j][key] + value - 1 >= max_dist_from_y:
                max_dist_from_y = special_to_0[j][key] + value - 1
                node_z = j
            break
ans = max(ans, max_dist_from_y)

# ANSWER
# print(node_x, node_y, node_z)
    
print(ans)