# My answer: All data copy, input three of '1' to '0' location and count all '2', '0' number.
#            If count have '2', area doesn't add count.
# Other's answer: Count '0' and '2' separately.
#                 Count '0' number except combinations of three '1' location.
#                 Start an infection at '2' and if the infection is successful, decrease the number of '0'.
#                 Returns the maximum number of '0'.

import copy

def find(lab, start, n, m):
    visit = set()
    move = [(-1,0), (1,0), (0,-1), (0,1)]
    isVirus = False
    area = []
    piece = 0
    for i in range(len(lab)):
        for j in range(len(lab[i])):
            if lab[i][j] != '1' and lab[i][j] != '3':
                if lab[i][j] == '2':
                    isVirus = True
                else:
                    isVirus = False
                visit.add((i,j))
                piece = 0
                while visit:
                    cx, cy = visit.pop()
                    lab[cx][cy] = '3'
                    piece += 1
                    for k in range(4):
                        mx, my = cx + move[k][0], cy + move[k][1]
                        if mx < 0 or my < 0 or mx >= n or my >= m:
                            continue
                        if lab[mx][my] == '2':
                            isVirus = True
                            visit.add((mx,my))
                        elif lab[mx][my] == '1' or lab[mx][my] == '3':
                            continue
                        elif lab[mx][my] == '0':
                            visit.add((mx, my))
                if not isVirus:
                    area.append(piece)
    return sum(area)

with open("14502_input.txt") as f:
    info = f.readline()
    while info:
        n, m = map(int, info.split())
        lab = []
        answer = 0
        for j in range(n):
            lab.append(f.readline().split())
        for k1 in range(n*m):
            if lab[k1//m][k1%m] == '0':
                for k2 in range(k1+1, n*m):
                    if lab[k2//m][k2%m] == '0':
                        for k3 in range(k2+1, n*m):
                            if lab[k3//m][k3%m] == '0':
                                newLab = copy.deepcopy(lab)
                                newLab[k1//m][k1%m] = '1'
                                newLab[k2//m][k2%m] = '1'
                                newLab[k3//m][k3%m] = '1'
                                area = find(newLab, (0,0), n, m)
                                if answer < area:
                                    answer = area
        print(answer)
        info = f.readline()
