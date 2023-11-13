#!/usr/bin/python3
from sys import argv


def isSafe(mat, r, c):
    for i in range(r):
        if mat[i][c] == 'Q':
            return False

    (i, j) = (r, c)
    while i >= 0 and j >= 0:
        if mat[i][j] == 'Q':
            return False
        i = i - 1
        j = j - 1

    (i, j) = (r, c)
    while i >= 0 and j < len(mat):
        if mat[i][j] == 'Q':
            return False
        i = i - 1
        j = j + 1

    return True


def printSolution(mat):
    i = 0
    print("[", end="")
    while(i < len(mat)):
        j = 0
        while(j < len(mat)):
            if (mat[i][j] == 'Q'):
                print(f"[{i}, {j}]", end="")
                if (i + 1 != len(mat)):
                    print(", ", end="")
            j += 1
        i += 1
    print("]")


def nQueen(mat, r):
    if r == len(mat):
        printSolution(mat)
        return

    for i in range(len(mat)):
        if isSafe(mat, r, i):
            mat[r][i] = 'Q'
            nQueen(mat, r + 1)
            mat[r][i] = '-'


if __name__ == '__main__':
    if (len(argv) != 2):
        print("Usage: nqueens N")
        exit(1)

    if (not argv[1].isdigit()):
        print("N must be a number")
        exit(1)

    if (int(argv[1]) < 4):
        print("N must be at least 4")
        exit(1)

    N = int(argv[1])
    mat = [['-' for x in range(N)] for y in range(N)]
    nQueen(mat, 0)
