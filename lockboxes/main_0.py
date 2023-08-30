#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes_recursion').canUnlockAll

if __name__ == "__main__":
    boxes = [
        [1],
        [8],
        [1],
        [2],
        [3],
        [4],
        [5],
        [6],
        [7]
    ]

    print(canUnlockAll(boxes))