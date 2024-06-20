n = int(input())
# print(bin(n))

seen = False

bin_rep = "0" + str(bin(n))[2:]
lans = 0
rans = 0
for i, bit in enumerate(bin_rep):
    if bit == "1" and not seen:
        seen = True
        lans += 2 ** (len(bin_rep) - i - 1)
        rans += 2 ** (len(bin_rep) - i - 1)
    elif bit == "1":
        lans += 2 ** (len(bin_rep) - i - 1)
        rans += 2 ** (len(bin_rep) - i)
        break

if abs(rans - n) < abs(lans - n):
    print(rans)
else:
    print(lans)