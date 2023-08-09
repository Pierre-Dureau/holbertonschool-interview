#!/usr/bin/python3
"""Determines if all the boxes can be opened"""

import sys
sys.setrecursionlimit(1001)


def unlock(boxes, box_opened, tab):
    """Unlock boxes recursively"""
    for n in box_opened:
        if (n >= len(tab) or tab[n] is True):
            continue
        tab[n] = True
        unlock(boxes, boxes[n], tab)


def canUnlockAll(boxes):
    """Unlock the first box and check the result"""
    if (len(boxes) == 0):
        return True

    tab = [False] * len(boxes)
    tab[0] = True

    unlock(boxes, boxes[0], tab)

    for check in tab:
        if check is False:
            return False

    return True
