import math

upto = int(5e6)
primes = [True for i in range(int(math.sqrt(upto)))]
product = 1
count = 0
for k, v in enumerate(primes):
    if k < 2:
        continue
    if v:
        product *= k
        if product > upto:
            break
        count += 1
        print(k, end=', ')
        for i in range(2 * k, len(primes), k):
            primes[i] = False
print('')
print(count)
