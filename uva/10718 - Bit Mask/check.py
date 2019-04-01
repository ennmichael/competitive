from random import randrange

def solve(target, lower, upper):
    max_value = 0
    mask = 0
    for i in range(lower, upper + 1):
        new_value = i | target
        if (new_value == max_value and i < mask) or new_value > max_value:
            max_value = new_value
            mask = i
    return mask

with open('in2', 'w') as in2, open('expected2', 'w') as expected2:
    for _ in range(50):
        target = randrange(1, 2**32)
        lower, upper = sorted([randrange(1, 2**32), randrange(1, 2**32)])
        in2.write(f'{target} {lower} {upper}\n')
        expected2.write(f'{solve(target, lower, upper)}\n')
