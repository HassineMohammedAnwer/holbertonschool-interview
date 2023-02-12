def minOperations(n):
    if n <= 0:
        return 0

    operations = 0
    i = 2
    while i <= n:
        while n % i == 0:
            operations += i
            n /= i
        i += 1
    operations += n

    return int(operations - 1)

