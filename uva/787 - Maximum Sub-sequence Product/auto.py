from random import randrange
from functools import reduce
import operator


def product(elements):
    return reduce(operator.mul, elements)


def solve(elements):
    result = -10000000000000
    for i in range(len(elements)):
        for j in range(i + 1, len(elements) + 1):
            result = max(result, product(elements[i:j]))
    return result


with open('in1', 'w') as in1, open('expected1', 'w') as expected1:
    for _ in range(10):
        num_elements = 10
        elements = [randrange(-50, 50) for _ in range (num_elements)]
        in1.write(' '.join(map(str, elements)) + ' -999999\n')
        expected1.write(f'{solve(elements)}\n')
