#!/bin/python3

import math
import os
import random
import re
import sys

#David has several containers, each with a number of balls in it. He has just enough containers to sort each type of ball he has into its own container. David wants to sort the balls using his sort method.
#You must perform queries where each query is in the form of a matrix, . For each query, print Possible on a new line if David can satisfy the conditions above for the given matrix. Otherwise, print Impossible. 

# Complete the organizingContainers function below.

#We can come to know if the sorting is possible by taking the sum of rows in a set and taking the sum of each columns in a set and compare them
def organizingContainers(container):
    #pass
    n=len(container[0])
    row=[]
    col=[]
    for i in range(n):
        row.append(0)
        col.append(0)
    for i in range(n):
        for j in range(n):
            row[i]+=container[i][j]
            col[j]+=container[i][j]
    row.sort()
    col.sort()
    if row==col:
        return "Possible"
    else:
        return "Impossible"
    
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        n = int(input())

        container = []

        for _ in range(n):
            container.append(list(map(int, input().rstrip().split())))

        result = organizingContainers(container)

        fptr.write(result + '\n')

    fptr.close()
