from itertools import permutations
from random import randrange


def cost(numbers):
    s = numbers[0] + numbers[1]
    cost = s
    for i in numbers[2:]:
        s += i
        cost += s
    return cost


def main():
    numbers = [randrange(25) for i in range(8)]
    print(numbers)
    min_cost, solution = min(
        ((cost(list(p)), list(p)) for p in permutations(numbers)),
        key=lambda t: t[0])
    print(solution)
    print(min_cost)

main()
