if __name__ == '__main__':
    upto = 46341
    primes = [True for i in range(upto)]
    for pk, pv in enumerate(primes):
        if pk < 2 or pv is False:
            continue
        for j in range(2 * pk, upto, pk):
            primes[j] = False

    primes = list(enumerate(primes))
    # primes.reverse()
    count = 0
    for k, v in primes:
        if v is True:
            print(k, end=', ')
            count += 1
            if (count % 6 == 0):
                print('')
    print(f'\n{count}')
