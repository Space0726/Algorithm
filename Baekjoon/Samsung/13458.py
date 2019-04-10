input()
An = list(map(int, input().split()))
superviser, sub = map(int, input().split())
answer = 0
for a in An:
    answer += 1
    a -= superviser
    if a > 0:
        answer += a // sub
        if a % sub:
            answer += 1
print(answer)
