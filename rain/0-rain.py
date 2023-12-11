#!/usr/bin/python3
"""Rain Module"""


def rain(walls):
    """return how many square units of water will be retained after it rains"""
    water = 0
    j = 0
    length = len(walls)

    if (length < 3):
        return 0

    for i in range(1, length):
        if (walls[i] >= walls[i - 1]) and (i == length - 1 or
                                          walls[i] > walls[i + 1]):
            height = walls[j] if walls[j] < walls[i] else walls[i]
            for k in range(j + 1, i):
                water += height - walls[k]
            j = i

    return water
