#!/usr/bin/python3
"""0. Pascal's Triangle"""


def pascal_triangle(n):
    """ returns a list of lists of integers representing
    __the Pascal’s triangle of n:
    Returns an empty list if n <= 0
    You can assume n will be always an integer"""
    if n <= 0:
        return []
    ll = [[1]]
    for i in range(1, n):
        row = [1]
        for j in range(1, i):
            row.append(ll[i-1][j-1] + ll[i-1][j])
        row.append(1)
        ll.append(row)
    return ll
