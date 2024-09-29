#!/usr/bin/python3
"""return he amount of
water that can be trapped
"""


def _max(x, y):
    """returnmax"""
    return x if x > y else y


def rain(walls):
    """return trapped rain"""
    if walls is None or walls == []:
        return 0
    if len(walls) == 1:
        return 0
    l = 0
    r = len(walls) - 1
    mx_l = walls[l]
    mx_r = walls[r]
    total_rain = 0

    while l < r:
        if mx_l < mx_r:
            l += 1
            mx_l = _max(walls[l], mx_l)
            total_rain += mx_l - walls[l]
        else:
            r -= 1
            mx_r = _max(walls[r], mx_r)
            total_rain += mx_r - walls[r]

    return total_rain
