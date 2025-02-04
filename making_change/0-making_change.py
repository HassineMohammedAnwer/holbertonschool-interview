#!/usr/bin/python3
"""0. Change comes from within"""


def makeChange(coins, total):
    """Given a pile of coins of different values, determine the
    __fewest number of coins needed to meet a given amount total.
    Prototype: def makeChange(coins, total)
    Return: fewest number of coins needed to meet total
    If total is 0 or less, return 0
    If total cannot be met by any number of coins you have, return -1
    coins is a list of the values of the coins in your possession
    The value of a coin will always be an integer greater than 0
    You can assume you have an infinite number of each denomination of coin in list
    Your solution’s runtime will be evaluated in this task"""
    if total <= 0:
        return 0
    if not coins or min(coins) > total:
        return -1
    c = 0
    coins.sort(reverse=True)
    x = 0
    while x < len(coins):
        if coins[x] <= total:
            c += total // coins[x]
            total = total % coins[x]
        x += 1
    if total == 0:
        return c
    else:
        return -1