#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'getMaxProduct' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

from collections import Counter

def getMaxProduct(arr):
    # Write your code here
    
    # 1. need to find k
    # 2. need to find number of integers to form the min cost
    # need to start from min selection then branch out from there
    
    combined = [(elem, i) for (i, part) in enumerate(arr) for elem in part]
    combined.sort()
    # print(Counter([b[0] for b in combined]))
    # print(combined)
    num_dict = { i : (len(arr[0]) + 1) // 2 for i in range(len(arr)) } 
    # print(num_dict)
    missing = len(arr)
    
    i = 0
    j = -1
    best_k = float('inf')
    res = 0
    last = (-1, -1)
    
    while (i, j) != last and i < len(combined):
        
        # print(i, j)
        last = (i, j)
        left_num = combined[i][0]
        right_num = combined[j][0]
        # print(left_num, right_num, "THISK", missing)
        
        while missing > 0 and j + 1 != len(combined):
            # extend right pointer
            j += 1
            right_num, where = combined[j]
            if num_dict[where] == 1:
                missing -= 1
            num_dict[where] -= 1
        if missing:
            break
        
        # print(left_num, right_num, "THISK", missing)
        
        # here, have a valid selection, and min cost
        this_k = right_num - left_num
        if this_k <= best_k:
            # find best result for this k
            m = j
            while m + 1 != len(combined) and combined[m + 1][0] == right_num:
                m += 1
            # print("BLAH", this_k, (m - i + 1), i, m)
            if this_k == best_k:
                res = max(this_k * (m - i + 1), res)
            else:
                res = this_k * (m - i + 1)
            best_k = this_k
        # have a selection that has given us a result, whether good or not, now move up a pointer and continue
        
        # print(num_dict, missing)
        # while missing == 0:
        left_num, where = combined[i]
        # THIS CODE CAUSED THE ISSUES OMG
        if num_dict[where] == 0:
            missing += 1
        num_dict[where] += 1
        i += 1
            
        # print()
    print(best_k)
    print(res)
    return res
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_rows = int(input().strip())
    arr_columns = int(input().strip())

    arr = []

    for _ in range(arr_rows):
        arr.append(list(map(int, input().rstrip().split())))

    result = getMaxProduct(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
