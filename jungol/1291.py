a, b = map(int, input().split())
while not (1 < a < 10) or not (1 < b < 10):
    print('INPUT ERROR!')
    a, b = map(int, input().split())
for i in range(1, 10):
    for j in range(a, b+1 if a < b else b-1, 1 if a < b else -1):
        if j != a:
            print('   ', end='')
        print("{0} * {1} = {2:2}".format(j, i, i*j), end='')
    print()
