#!/usr/bin/python3
"""0. Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    """Given an n x n 2D matrix, rotate it 90 degrees clockwise.
    Prototype: def rotate_2d_matrix(matrix):
    Do not return anything. The matrix must be edited in-place.
    You can assume the matrix will have 2 dimensions and will not be empty."""
    n = matrix.shape[1]
    start = 0
    tmp = matrix[0][0]
    while start < n:
        for i in range(start, n):
            tmp = matrix[start][i]
            matrix[start][i] = matrix[i][start]
            matrix[i][start] = tmp
        start += 1
    for i in range(n):
        matrix[i].reverse()
