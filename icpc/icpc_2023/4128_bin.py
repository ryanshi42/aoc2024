





# s00 = a
# s01 = b
# s10 = c
# s11 = d

# algorithm: put a zeroes, then put d ones

# 010
# 001

# 100


import math
import random



done = 0
blah = 0
# initialize list
for i in range(1, 10000000000):

    test_list = [random.uniform(0,1) for _ in range(i)]
    
    # printing original list
    # print("The original list is : " + str(test_list))
    
    # Geometric Mean of List
    # using loop + formula
    temp = 1
    for i in range(0, len(test_list)) :
        temp = pow(test_list[i], (1 / len(test_list)))

        # print(temp)
    # print(temp)
    # temp2 = (float)(pow(temp, (1 / len(test_list))))
    temp2 = (float)(temp)
    res = (float)(temp2)
    if str(res) != "inf":
        done += 1
        blah += res
        print(blah / done)

    
    # printing result
    print("The geometric mean of list is : " + str(res), len(test_list))
    if str(res) == "inf":
        break

# (((n * 2^((n+1)/n)) - (n * 1^((n+1)/n)))/(n+1))^n