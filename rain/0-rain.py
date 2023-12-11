#!/usr/bin/python3
""" Rain Module """

def rain(walls):
    """return how many square units of water will be retained after it rains"""
    water = 0
    j = 0
    space = 0

    for i in walls:
        if i == 0:
            space += 1
        else:
            if i < j:
                water += i * space
            else:
                water += j * space
            j = i
            space = 0
    return water
