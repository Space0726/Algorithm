N = int(input())
sq = [[0 for _ in range(N)] for _ in range(N)]
cnt = 0
for i in range((N+2)//3):
    for j in range(N-3*i):
        sq[i*2+j][i+j] = cnt
        cnt += -9 if cnt == 9 else 1
    for j in range(N-2-i*2, i-1, -1):
        sq[-i-1][j] = cnt
        cnt += -9 if cnt == 9 else 1
    for j in range(N-2-i, i*2, -1):
        sq[j][i] = cnt
        cnt += -9 if cnt == 9 else 1
for i in range(N):
    for j in range(i+1):
        print(sq[i][j], end=' ')
    print()
