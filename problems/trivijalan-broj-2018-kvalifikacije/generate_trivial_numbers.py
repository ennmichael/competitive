#!/usr/bin/env python3

from math import sqrt


UPTO = int(5e6)


PRIMES = [2, 3, 5, 7, 11, 13, 17]


def factors(n):
    for p in PRIMES:
        if n % p == 0:
            n /= p
            yield p


def divisors(n):
    for i in range(1, int(sqrt(n))):
        if n % i == 0:
            yield i


def triviality(n):
    return sum(divisors(n)) / n


if __name__ == '__main__':
    print(0, end=', ')
    for i in range(1, UPTO + 1):
        if i % 20 == 0:
            print('')
        print(triviality(i), end=', ')

