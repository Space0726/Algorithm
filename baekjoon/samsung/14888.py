from itertools import permutations

def operate(a, b, op):
    if op == 0:
        return a+b
    elif op == 1:
        return a-b
    elif op == 2:
        return a*b
    else:
        if (a < 0 and b > 0) or (a > 0 and b < 0):
            return -(-a//b)
        return a//b

n = int(input())
a = list(map(int, input().split()))
ops = list(map(int, input().split()))
op = []
for i in range(4):
    for j in range(ops[i]):
        op.append(i)
ops = list(permutations(op, n-1))
max_ = -1000000000
min_ = 1000000000
for o in ops:
    result = a[0]
    for i in range(n-1):
        result = operate(result, a[i+1], o[i])
    if result > max_:
        max_ = result
    if result < min_:
        min_ = result
print(max_)
print(min_)
