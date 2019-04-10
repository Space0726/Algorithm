def move(miro, x, y):
    if miro[x][y] == '3':
        return 1
    visited = []
    visited.append((x,y))
    movePoint = [(-1,0), (1,0), (0,-1), (0,1)]
    while visited:
        x, y = visited.pop()
        if miro[x][y] == '3':
            return 1
        miro[x][y] = '2'
        for i in range(4):
            mx = x + movePoint[i][0]
            my = y + movePoint[i][1]
            if mx < 0 or my < 0 or mx > 99 or my > 99:
                continue
            if miro[mx][my] == '3':
                return 1
            elif miro[mx][my] == '2' or miro[mx][my] == '1':
                continue
            miro[mx][my] = '2'
            visited.append((mx, my))
    return 0
        

with open("1227_input.txt") as f:
    case = f.readline()[:-1]
    while case:
        miro = []
        x, y = 0, 0
        for i in range(100):
            miro.append(list(f.readline())[:-1])
            if '2' in miro[-1]:
                x, y = i, miro[-1].index('2')
        print(f'#{case} {move(miro, x, y)}')
        case = f.readline()[:-1]
