#!/usr/bin/python3
"""Module of Prime Game"""


def isWinner(x, nums):
    """Return the winner between Maria and Ben"""
    ben = 0
    maria = 0

    for i in range(0, x):
        turn = 0
        tab = [j for j in range(1, nums[i] + 1)]

        while (len(tab) > 1):
            choice = tab[1]
            temp = []
            for k in tab:
                if (k % choice == 0):
                    temp.append(k)
            tab = temp
            turn += 1

        if (turn % 2 == 0):
            ben += 1
        else:
            maria += 1

    if ben != 0 or maria != 0:
        if ben > maria:
            return "Ben"
        else:
            return "Maria"
