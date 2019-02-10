# Answer is correct but timeout
n, k = map(int, input().split())
li = list(map(int, input().split()))
dv = -1
for i in range(k, n):
    for j in range(n-k+1):
        avg = sum(li[j:i+j]) / i
        t = sum(map(lambda x: (x - avg) ** 2, li[j:i+j]))
        if dv > t / i or dv == -1:
            dv = t / i
print(dv ** 0.5)
