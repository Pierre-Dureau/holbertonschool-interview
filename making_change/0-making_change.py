#!/usr/bin/python3
"""
Make Change function
"""


def makeChange(coins, total):
    """Determine the fewest number of coins needed to meet a given amount"""
    n = 0

    if (total <= 0):
        return 0

    while (total != 0):
        highest = 0
        for coin in coins:
            if (coin > highest and coin <= total):
                highest = coin
        if (highest == 0):
            return -1
        while (highest <= total):
            total -= highest
            n += 1

    return n
