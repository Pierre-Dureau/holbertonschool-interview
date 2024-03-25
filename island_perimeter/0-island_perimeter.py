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
                if (i == (len(grid) - 1) or grid[i + 1][j] == 0):
                    count += 1
                if (i == 0 or grid[i - 1][j] == 0):
                    count += 1
                if (j == (len(grid[0]) - 1) or grid[i][j + 1] == 0):
                    count += 1
                if (j == 0 or grid[i][j - 1] == 0):
                    count += 1
    return count
