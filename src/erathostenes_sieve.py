#!/usr/bin/env python3


import sys
import math
import itertools


def floor_sqrt(n):
    return math.floor(math.sqrt(n))


def sieve(upto):
    all_numbers = list(itertools.repeat(True, upto));
    for i in range(2, floor_sqrt(upto)):
        for j in range(i * i, upto, i):
            all_numbers[j] = False
    return (k for k, v in enumerate(all_numbers) if v)


if __name__ == '__main__':
    primes = list(sieve(int(sys.argv[1])))
    print(', '.join(str(n) for n in primes))
    print(len(primes))

