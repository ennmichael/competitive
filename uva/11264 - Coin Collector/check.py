from itertools import permutations
from random import randrange


def count_coins(coins, money):
    count = 0
    for coin in coins:
        if coin > money:
            continue

        while coin <= money and money > 0:
            money -= coin
        count += 1

    return count


def sublists(l):
    for i in range(1, len(l) + 1):
        yield l[:i]


def best(coins, in_file, out_file):
    in_file.write(f'{len(coins)}\n')
    in_file.write(' '.join(map(str, reversed(coins))) + '\n')
    all_counts = [(count_coins(coins, sum(p)), p) for p in sublists(coins)]
    m = max(all_counts, key=lambda x: x[0])
    out_file.write(f'{m[0]}\n')
    for c in all_counts:
        if m[0] == c[0]:
            print(c)


with open('in1', 'w') as in_file, open('out1', 'w') as out_file:
    in_file.write("50\n")
    for i in range(50):
        l = list(set(randrange(2, 50) for i in range(7)))
        l = sorted(l, key=lambda x: -x)
        l.append(1)
        best(l, in_file, out_file)
