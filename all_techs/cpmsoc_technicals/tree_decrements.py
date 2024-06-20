#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'getMinCost' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY val
#  2. UNWEIGHTED_INTEGER_GRAPH t
#

#
# For the unweighted graph, <name>:
#
# 1. The number of nodes is <name>_nodes.
# 2. The number of edges is <name>_edges.
# 3. An edge exists between <name>_from[i] and <name>_to[i].
#
# Dodgy question, can't assume is binary tree apparently???? So confused

def getMinCost(val, t_nodes, t_from, t_to):
    
    for i in range(len(val)):
        val[i] = val[i]%2
    adj_list = [set() for i in range(t_nodes)]
    for i in range(len(t_from)):
        adj_list[t_from[i]-1].add(t_to[i]-1)
        adj_list[t_to[i]-1].add(t_from[i]-1)
    
    leaves = [i for i in range(t_nodes) if len(adj_list[i]) == 1]
    
    remaining = t_nodes 
    cost = 0 
    while leaves and remaining > 2:
        remaining -= len(leaves) 
        newLeaves = []
        for leaf in leaves:
            #each leaf only has one parent so pop() any from adj_list
            parent = adj_list[leaf].pop() 
            #remove leaf from parent to check if parent becomes a leaf
            adj_list[parent].remove(leaf) 
            if val[leaf] == 1: #odd
                cost += 1
                # parnt shd change fm 0 to 1 and vice versa
                val[parent] = 1 - val[parent]
                
            if len(adj_list[parent]) == 1:
                newLeaves.append(parent)
                
        leaves = newLeaves
    
    # check if remaining two leaves are odd
    if leaves and val[leaves[0]] == 1:
        cost += 1
    return cost
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    val_count = int(input().strip())

    val = []

    for _ in range(val_count):
        val_item = int(input().strip())
        val.append(val_item)

    t_nodes, t_edges = map(int, input().rstrip().split())

    t_from = [0] * t_edges
    t_to = [0] * t_edges

    for i in range(t_edges):
        t_from[i], t_to[i] = map(int, input().rstrip().split())

    result = getMinCost(val, t_nodes, t_from, t_to)

    fptr.write(str(result) + '\n')

    fptr.close()
