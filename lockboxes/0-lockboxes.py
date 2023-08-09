#!/usr/bin/python3

def unlock(boxes, box_opened, tab):
    for n in box_opened:
        if (tab[n] == True):
            return
        tab[n] = True
        unlock(boxes, boxes[n], tab)
        

def canUnlockAll(boxes):
    if (len(boxes) == 0):
        return True
    
    tab = [False] * len(boxes)
    tab[0] = True

    unlock(boxes, boxes[0], tab)
    
    for check in tab:
        if check == False:
            return False
        
    return True
