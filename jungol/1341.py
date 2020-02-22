a, b = map(int, input().split())
for i in range(a, b+1 if a < b else b-1, 1 if a < b else -1):
    for j in range(1, 10):
        if (j-1) % 3:
            print('   ', end='')
        print("{0} * {1} = {2:2}".format(i, j, i*j), end='')
        if not j%3:
            print()
    print()
