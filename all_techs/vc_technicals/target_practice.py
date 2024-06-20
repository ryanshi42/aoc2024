a = int(input())
b = int(input())
c = int(input())

targets = [a, b, c]
targets.sort()

moves = 0
while not (targets[0] == targets[1] - 1 and targets[1] == targets[2] - 1):
    moves += 1
    ldist = abs(targets[1] - targets[0])
    rdist = abs(targets[2] - targets[1])
    if ldist < rdist:
        targets[0] = targets[1] + ldist
        if targets[0] == targets[2]:
            targets[0] += 1
    else:
        targets[2] = targets[1] - rdist
        if targets[0] == targets[2]:
            targets[2] -= 1
    targets.sort()

print(moves)
