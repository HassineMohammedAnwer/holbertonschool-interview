#!/usr/bin/python3
"""method """


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened.
    Each box is numbered sequentially from 0 to n - 1
    and each box may contain keys to the other boxes."""
    res = False
    i = 1
    j = 0
    ind_1 = 0
    while (i < len(boxes)):
        while (j < len(boxes)):
            if j == i:
                j = j + 1
                continue
            while (ind_1 < len(boxes[j])):
                if (i == boxes[j][ind_1]):
                    res = True
                    break
                else:
                    ind_1 = ind_1 + 1
            if res is True:
                break
            else:
                j = j + 1
                ind_1 = 0
        if res is False and j != i:
            return False
        else:
            j = 0
            i = i + 1
            res = False
    return True
