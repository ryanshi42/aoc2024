

n = int(input())

ans = []

for i in range(n):
    j, x = input().split()

    o = 0
    hd = 0

    for l, char in enumerate(x):
        #hd += int(char) * (16 ** (len(x) - l - 1))
        hd += int(char) << (4*(len(x) - l - 1))
    # hd = int("0x" + x)
    
    for l, char in enumerate(x):
        if char == "9" or char == "8":
            o = 0
            break
        #o += int(char) * (8 ** (len(x) - l - 1))
        o += int(char) << (3*(len(x) - l - 1))
    # try:
    #     o = int("0o" + x)
    # except:
    #     o = 0

    ans.append((j, o, x, hd))

for elem in ans:
    print(" ".join(map(str, elem)))