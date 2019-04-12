from itertools import combinations as C

# My answer

'''
def getDiff(ab, n, start):
    dict_ = dict(zip(start, filter(lambda x: x not in start, range(n))))
    start = list(C(start, 2))
    link = [tuple(map(lambda x: dict_[x], s)) for s in start]
    diff = abs(sum([ab[start[i][0]][start[i][1]] - ab[link[i][0]][link[i][1]] for i in range(len(start))]))
    return diff

n = int(input())
ab = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):
    for j in range(i, n):
        ab[i][j] += ab[j][i]
team = list(C(range(n), n//2))
answer = 1000000000
for t in team:
    d = getDiff(ab, n, t)
    if answer > d:
        answer = d
    if d == 0:
        break
print(answer)
'''

# Other's answer

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
answer = 0xffffff
member = set(range(n))
for c in C(range(n), n//2):
    temp = 0
    for x, y in C(c, 2):
        temp += a[x][y] + a[y][x]
    for x, y in C(member - set(c), 2):
        temp -= a[x][y] + a[y][x]
    answer = min(answer, abs(temp))
    if answer == 0:
        break
print(answer)
