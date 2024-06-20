
import sys

num = input()



def add_one_to_bn(A):
    A = list(A)
    carry = False
    for i in range(len(A)-1, -1, -1):
        if A[i] == "0":
            A[i] = "1"
            carry = False
            break
        else:
            carry = True
            A[i] = "0"
    if carry:
        return "".join(["1"] + A)
    else:
        return "".join(A)

        

if num == "1":
    print(10)
    sys.exit(0)

bn = "0"

for i in range(0, int(num)):
    # print(i)
    bn = add_one_to_bn(bn)
    # print(bn)
    if bn in num:
        continue
    else:
        print(bn)
        break