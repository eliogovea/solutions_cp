#!/bin/python3

import math
import os
import random
import re
import sys

def zFunction(s):
    n = len(s)
    l, r = -1, -1
    z = [0] * n
    for i in range(1, n):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while i + z[i] < n and s[i + z[i]] == s[z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l = i
            r = i + z[i] - 1
    return z

# Complete the stringSimilarity function below.
def stringSimilarity(s):
    return len(s) + sum(zFunction(s))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        s = input()

        result = stringSimilarity(s)

        fptr.write(str(result) + '\n')

    fptr.close()

