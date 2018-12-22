if __name__ == '__main__':
    upto = 448
    t = [True for i in range(upto)]
    t[0] = t[1] = False
    for i in range(2, upto):
        for j in range(2 * i, upto, i):
            t[j] = False
    count = 0
    l = list(enumerate(t))
    l.reverse()
    for k, v in l:
        if v is True:
            count += 1
            print(k, end=', ')
    print('')
    print(count)
