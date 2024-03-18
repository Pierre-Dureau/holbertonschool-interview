#!/usr/bin/python3
"""
Module island_perimeter
"""


def island_perimeter(grid):
    """returns the perimeter of the island described in grid"""
    count = 0
    for i in range(0, len(grid)):
        for j in range(0, len(grid[0])):
            if (grid[i][j] == 1):
                if (grid[i + 1][j] == 0):
                    count += 1
                if (grid[i - 1][j] == 0):
                    count += 1
                if (grid[i][j + 1] == 0):
                    count += 1
                if (grid[i][j - 1] == 0):
                    count += 1
    return count
