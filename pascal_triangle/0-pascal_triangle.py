#!/usr/bin/python3
"""Module Pascal's triangle"""


def pascal_triangle(n):
    """that returns a list of lists of integers
    representing the Pascal’s triangle of n"""
    if n <= 0:
        return []

    pascal = [[1]]

    for i in range(1, n):
        line = pascal[i - 1].copy()
        new_line = [1]
        for j in range(1, i):
            new_line.append(line[j - 1] + line[j])
        new_line.append(1)
        pascal.append(new_line)

    return pascal
