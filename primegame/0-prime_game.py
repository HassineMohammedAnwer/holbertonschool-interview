#!/usr/bin/python3
"kjnmj"


def isWinner(x, nums):
    """dmk,"""
    if x <= 0:
        return None
    n = 10000
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    count_primes = [0] * (n + 1)
    for i in range(1, n + 1):
        count_primes[i] = count_primes[i - 1] + (1 if is_prime[i] else 0)
    maria_wins = 0
    ben_wins = 0
    for n in nums:
        k = count_primes[n]
        if k % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
