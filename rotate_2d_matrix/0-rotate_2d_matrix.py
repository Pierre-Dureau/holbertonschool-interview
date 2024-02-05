#!/usr/bin/python3
"""
Module rotate 2D matrix
"""


def rotate_2d_matrix(matrix):
    """Rotate a 2D matrix at 90°"""
    matrix_copy = [line.copy() for line in matrix]
    length = len(matrix) - 1
    for i in range(len(matrix_copy)):
        for j in range(len(matrix_copy[i])):
            matrix[j][length] = matrix_copy[i][j]
        length -= 1
