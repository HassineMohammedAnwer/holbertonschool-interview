#!/usr/bin/python3
import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    n = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)
if n < 4:
    print("N must be at least 4")
    exit(1)

def is_valid(board, row, col):
    for r, c in board:
        if col == c or row + col == r + c or row - col == r - c:
            return False
    return True

def nqueens(n, board=[]):
    if len(board) == n:
        print([list(pos) for pos in board])
        return
    for col in range(n):
        if is_valid(board, len(board), col):
            board.append((len(board), col))
            nqueens(n, board)
            board.pop()

nqueens(n)

