#!/usr/bin/python3
"""Determines if all the boxes can be opened"""


def unlock(box_opened, tab):
    """Unlock boxes recursively"""
    for n in box_opened:
        if (n >= len(tab) or tab[n] is True):
            continue
        tab[n] = True


def canUnlockAll(boxes):
    """Unlock the first box and check the result"""
    if (len(boxes) == 0):
        return True

    tab = [False] * len(boxes)
    tab[0] = True

    for i in range(len(boxes)):
        if tab[i] is True:
            unlock(boxes[i], tab)

    for check in tab:
        if check is False:
            return False

    return True
