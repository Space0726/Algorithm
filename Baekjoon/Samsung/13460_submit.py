def solve(board, red, blue):
    board[red[0]][red[1]] = '.'
    board[blue[0]][blue[1]] = '.'
    dict_ = dict([[i,set()] for i in range(10)])
    dict_[0].add((red, blue))
    moves = [(-1,0), (1,0), (0,-1), (0,1)]
    for i in range(10):
        while dict_[i]:
            r, b = dict_[i].pop()
            for j in range(4):
                rx, ry = r[0]+moves[j][0], r[1]+moves[j][1]
                bx, by = b[0]+moves[j][0], b[1]+moves[j][1]
                rFlag, bFlag = True, True
                isRedLong = False
                while rFlag or bFlag:
                    if rFlag and not bFlag:
                        isRedLong = True
                    elif not rFlag and bFlag:
                        isRedLong = False
                    if board[rx][ry] != '.':
                        rFlag = False
                    if board[bx][by] != '.':
                        bFlag = False
                    if rFlag:
                        rx += moves[j][0]
                        ry += moves[j][1]
                    if bFlag:
                        bx += moves[j][0]
                        by += moves[j][1]
                if board[bx][by] == 'O':
                    continue
                if board[rx][ry] == 'O':
                    return i+1
                rx -= moves[j][0]
                ry -= moves[j][1]
                bx -= moves[j][0]
                by -= moves[j][1]
                if rx == bx and ry == by:
                    if isRedLong:
                        rx -= moves[j][0]
                        ry -= moves[j][1]
                    else:
                        bx -= moves[j][0]
                        by -= moves[j][1]
                if i == 9:
                    continue
                dict_[i+1].add(((rx,ry),(bx,by)))
    return -1

n, _ = map(int, input().split())
board = []
for j in range(n):
    board.append(list(input()))
    if 'R' in board[-1]:
        red = (j, board[-1].index('R'))
    if 'B' in board[-1]:
        blue = (j, board[-1].index('B'))
print(solve(board, red, blue))