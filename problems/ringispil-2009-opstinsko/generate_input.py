#!/usr/bin/env python3


import random


if __name__ == '__main__':
    N = 500
    K = 1000
    R = 3

    print(N)
    for i in range(N):
        row = (i * N + j for j in range(N))
        print(' '.join(map(str, row)))

    print(K)
    for i in range(K):
        r = round(N / 2)
        print(i % r + 1, R)
