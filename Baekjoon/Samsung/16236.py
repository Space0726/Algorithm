from itertools import chain
from collections import Counter

def bfs(sea, n, fdict, start, size):
    if 1 not in fdict:
        return 0
    moves = [(-1,0), (1,0), (0,-1), (0,1)]
    visited = set()
    find = { 0:set([start]) }

    # 총 이동횟수
    answer = 0

    # 먹은 물고기 개수
    fstack = 0

    # 먹을 수 있는 물고기 수
    possible = fdict[1]

    # 먹을 수 있는 물고기 있는지
    while possible:

        # 이동횟수
        cnt = 0

        # 물고기 먹었는지 여부
        isEat = False

        # 먹을 수 있는 물고기 위치
        posEat = (20, 20)

        # 물고기 먹을때까지 탐색 및 이동
        while find[cnt]:
            cx, cy = find[cnt].pop()
            visited.add((cx,cy))

            # 제자리에서 먹을 수 있을 경우
            if sea[cx][cy] != 0 and sea[cx][cy] < size:
                if posEat[0] > cx:
                    posEat = (cx,cy)
                elif posEat[0] == cx and posEat[1] > cy:
                    posEat = (cx,cy)

            # 전방향 탐색
            for i in range(4):
                x, y = cx+moves[i][0], cy+moves[i][1]
                
                # 위치가 벗어날 경우 넘어가기
                if x < 0 or y < 0 or x >= n or y >= n:
                    continue

                # 방문한 곳이 아니라면
                if (x, y) not in visited:
                    # 그 곳으로 이동할 수 있는지 체크
                    if sea[x][y] <= size:
                        if cnt+1 not in find:
                            find[cnt+1] = set([(x, y)])
                        else:
                            find[cnt+1].add((x,y))

            # 이동할 곳이 없으면, 다음 이동 탐색
            if len(find[cnt]) == 0:

                # 탐색 마친 후 가장 우선순위 높은 곳의 물고기 먹기
                if posEat != (20,20):
                    cx, cy = posEat
                    fdict[sea[cx][cy]] -= 1
                    sea[cx][cy] = 0
                    fstack += 1

                    # 레벨업만큼 먹었을 경우
                    if fstack == size:
                        size += 1
                        fstack = 0

                    # 지금 자리에서부터 다시 물고기 탐색 시작, 초기화 작업 수행
                    find = { 0:set([(cx,cy)]) }
                    visited = set()
                    isEat = True
                    answer += cnt

                    # 먹을 수 있는 물고기의 총 마릿수 저장
                    possible = sum([fdict[i] for i in range(1, min(size, 7)) if i in fdict])
                    break
                
                # 이동할 곳이 있으면 넘어가기
                if cnt+1 in find:
                    cnt += 1

        # 물고기를 못 먹고 모두 탐색한 경우 - 먹을 수 있는 물고기가 없음
        if not isEat:
            return answer

    return answer

            

n = int(input())
sea = []
for i in range(n):
    sea.append(list(map(int, input().split())))
    if 9 in sea[-1]:
        shark = (i, sea[-1].index(9))

# 상어가 있는 곳 초기화
sea[shark[0]][shark[1]] = 0

# 크기별 물고기의 수 저장
fdict = dict(Counter(chain(*sea)))

# 물고기가 없는 곳 제거
if 0 in fdict:
    del(fdict[0])

print(bfs(sea, n, fdict, shark, 2))
