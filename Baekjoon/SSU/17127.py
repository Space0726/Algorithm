from functools import reduce

n = int(input())
li = list(map(int, input().split()))
l = []
for a in range(1, n-2):
    for b in range(1, n-a):
        for c in range(1, n-a-b):
            l.append([a, b, c, n-a-b-c])
answer = 0
for s in l:
    temp = 0
    value = 0
    for e in s:
        value += reduce(lambda x, y: x*y, li[temp:temp+e])
        temp += e
    answer = max(answer, value)
print(answer)
