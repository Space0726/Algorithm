n = int(input())
t = []
for i in range(n):
    t.append(list(map(int, input().split())))
check = [False for i in range(n)]
# answer = 0
for i in range(n-1, -1, -1):
    if t[i][0] > n - i:
        continue
    if t[i][0] == 1:
        check[i] = True
        # answer += t[i][1]
    else:
        piece = sum([t[j][1] for j in range(i,i+t[i][0]) if check[j]])
        if t[i][1] > piece:
            # answer += t[i][1] - piece
            check[i] = True
            for j in range(i+1, i+t[i][0]):
                check[j] = False
            for j in range(i+t[i][0], n):
                if check[j]:
                    fix = list(range(i+t[i][0],j))
                    for k in reversed(fix):
                        if t[k][0] > fix[-1]+1 - k:
                            continue
                        if t[k][0] == 1:
                            check[k] = True
                            # answer += t[k][1]
                        else:
                            piece2 = sum(t[m][1] for m in range(k,k+t[k][0]) if check[j])
                            if t[k][1] > piece:
                                # answer += t[k][1] - piece2
                                check[k] = True
                                for n in range(k+1, k+t[k][0]):
                                    check[n] = False
print(sum([t[i][1] for i, c in enumerate(check) if c]))
