from random import randrange


NUM_TEST_CASES = 20

NUM_VESSELS = 10


def random_vessels():
    return (str(randrange(3, 50)) for _ in range(NUM_VESSELS))


def num_containers():
    return randrange(1, NUM_VESSELS - 1)


for i in range(NUM_TEST_CASES):
    print(f'{NUM_VESSELS} {num_containers()}')
    print(' '.join(random_vessels()))
