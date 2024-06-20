n = int(input())
poles = input()

opp = {
    "+": "-",
    "-": "+"
}
last = ""
groups = 1
for i in range(len(poles)):
    if i == 0:
        last = poles[i]
    else:
        if opp[last] != poles[i]:
            groups += 1
        last = poles[i]

print(groups)