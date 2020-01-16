import sys
sys.stdin = open("17143_input.txt")

R, C, M = map(int, input().split())
sharks = []
sea = [[0 for _ in range(C)] for _ in range(R)]
direct = [(-1, 0), (1, 0), (0, 1), (0, -1)]

class shark:
    def __init__(self, r, c, s, d, z):
        self.r = r - 1
        self.c = c - 1
        self.s = s
        self.d = d - 1
        self.z = z

    def __repr__(self):
        return str(self.z)


def set_sea():
    global sea
    sea = [[0 for _ in range(C)] for _ in range(R)]
    remove_shark = []
    for shark in sharks:
        r, c = shark.r, shark.c
        if sea[r][c]:
            if sea[r][c].z < shark.z:
                remove_shark.append(sea[r][c])
                sea[r][c] = shark
            else:
                remove_shark.append(shark)
        else:
            sea[r][c] = shark
    for shark in remove_shark:
        sharks.remove(shark)

def catch(t):
    for row in range(R):
        if sea[row][t]:
            idx = sharks.index(sea[row][t])
            sea[row][t] = 0
            return sharks.pop(idx).z
    return 0

def move():
    for shark in sharks:
        dy, dx = direct[shark.d]
        # 방향이 아래 또는 오른쪽
        if shark.d % 3:
            # 방향이 아래일 때
            if shark.d == 1:
                temp = shark.r + shark.s
                # 방향 바뀔 때
                if (temp // R) % 2:
                    temp = R - 1 - (temp % R + 1)
                else:
                    temp = temp % (R-1)
                shark.r = temp
            # 방향이 오른쪽일 때
            else:
                temp = shark.c + shark.s
                # 방향 바뀔 때
                if (temp // C) % 2:
                    temp = C - 1 - temp % (C-1)
                else:
                    temp = temp % (C-1)
                shark.c = temp
        # 방향이 위 또는 왼쪽
        else:
            # 방향이 위일 때
            if shark.d == 0:
                temp = abs(shark.r - shark.s)
                # 방향 바뀔 때
                if (temp // R) % 2:
                    temp = temp % R
                else:
                    temp = R - 1 - (temp % R + 1)
                shark.r = temp
            # 방향이 왼쪽일 때
            else:
                temp = abs(shark.c - shark.s)
                # 방향 바뀔 때
                if (temp // C) % 2:
                    temp = temp % C
                else:
                    temp = C - 1 - temp % (C-1)
                shark.c = temp

        """
        for _ in range(shark.s):
            shark.r += dy
            shark.c += dx
            if shark.r < 0:
                shark.r = 1
                shark.d = 1
                dy, dx = direct[shark.d]
            elif shark.r >= R:
                shark.r -= 2
                shark.d = 0
                dy, dx = direct[shark.d]
            if shark.c < 0:
                shark.c = 1
                shark.d = 2
                dy, dx = direct[shark.d]
            elif shark.c >= C:
                shark.c -= 2
                shark.d = 3
                dy, dx = direct[shark.d]
        """

for i in range(4):
    if i:
        R, C, M = map(int, input().split())
        sharks = []
        sea = [[0 for _ in range(C)] for _ in range(R)]
        direct = [(-1, 0), (1, 0), (0, 1), (0, -1)]
    if not M:
        print(0)
    else:
        for _ in range(M):
            sharks.append(shark(*list(map(int, input().split()))))
            sea[sharks[-1].r][sharks[-1].c] = sharks[-1]

        answer = 0
        for sec in range(C):
            print(sea)
            print(sharks)
            answer += catch(sec)
            move()
            set_sea()
            print(sea)
            print(sharks)

        print(answer)
