#!/usr/bin/python3
"""
Method that calculates the fewest number of operations needed
"""


def minOperations(n):
    if (n < 1):
        return 0

    letters = 1
    copy = 0
    nbOpe = 0

    while (letters != n):
        if (n % letters == 0):
            copy = letters
            nbOpe += 1
        letters += copy
        nbOpe += 1

    return nbOpe
