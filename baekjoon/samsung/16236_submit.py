from itertools import chain
from collections import Counter

def bfs(sea, n, fdict, start, size):
    if 1 not in fdict:
        return 0
    moves = [(-1,0), (1,0), (0,-1), (0,1)]
    visited = set()
    find = { 0:set([start]) }
    answer = 0
    fstack = 0
    possible = fdict[1]
    while possible:
        cnt = 0
        isEat = False
        posEat = (20, 20)
        while find[cnt]:
            cx, cy = find[cnt].pop()
            visited.add((cx,cy))
            if sea[cx][cy] != 0 and sea[cx][cy] < size:
                if posEat[0] > cx:
                    posEat = (cx,cy)
                elif posEat[0] == cx and posEat[1] > cy:
                    posEat = (cx,cy)
            for i in range(4):
                x, y = cx+moves[i][0], cy+moves[i][1]
                if x < 0 or y < 0 or x >= n or y >= n:
                    continue
                if (x, y) not in visited:
                    if sea[x][y] <= size:
                        if cnt+1 not in find:
                            find[cnt+1] = set([(x, y)])
                        else:
                            find[cnt+1].add((x,y))
            if len(find[cnt]) == 0:
                if posEat != (20,20):
                    cx, cy = posEat
                    fdict[sea[cx][cy]] -= 1
                    sea[cx][cy] = 0
                    fstack += 1
                    if fstack == size:
                        size += 1
                        fstack = 0
                    find = { 0:set([(cx,cy)]) }
                    visited = set()
                    isEat = True
                    answer += cnt
                    possible = sum([fdict[i] for i in range(1, min(size, 7)) if i in fdict])
                    break
                if cnt+1 in find:
                    cnt += 1
        if not isEat:
            return answer
    return answer

n = int(input())
sea = []
for i in range(n):
    sea.append(list(map(int, input().split())))
    if 9 in sea[-1]:
        shark = (i, sea[-1].index(9))
sea[shark[0]][shark[1]] = 0
fdict = dict(Counter(chain(*sea)))
if 0 in fdict:
    del(fdict[0])
print(bfs(sea, n, fdict, shark, 2))