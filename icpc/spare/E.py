n = int(input())

valid = set()

f = True

# only y-z plane now
for z in range(n-1, -1, -1):
    # y-z plane
    row = input()
    for y in range(n):
        if row[y] == '1':
            f = False
            for x in range(n):
                valid.add((x, y, z))


# xz
monk2 = set()
for x in range(n-1, -1, -1):
    row = input()
    for z in range(n):
        if row[z] == '1':
            f = False
            for y in range(n):
                if (x, y, z) in valid:
                    monk2.add((x,y,z))
# xy
monk3 = set()
for y in range(n-1, -1, -1):
    row = input()
    for x in range(n):
        if row[x] == '1':
            f = False
            for z in range(n):
                if (x, y, z) in monk2:
                    monk3.add((x,y,z))

# print((valid))
# print((monk2))
# print((monk3))

if monk3 or f:
    print("Yes")
else:
    print("No")