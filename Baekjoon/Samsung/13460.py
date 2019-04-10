import numpy as np

def solve(board, start, n, m, answers=[], count=0, end=True):
    if count >= 11:
        return
    moves = [(-1,0), (1,0), (0,-1), (0,1)]
    for i in range(4):
        mx = moves[i][0]+ start[0]
        my = moves[i][1] + start[1]
        if mx < 0 or my < 0 or mx >= n or my >= m:
            continue
        if board[mx][my] == '.':
            continue
        elif board[mx][my] == '#':
            solve(board, (mx, my), n, m, answers, count+1, False)
        elif board[mx][my] == 'O':
            answers.append(count)
            break
    if end:
        return answers

with open("13460_input.txt") as f:
    for i in range(7):
        n, m = map(int, f.readline().split())
        board = []
        for j in range(n):
            board.append(list(filter(lambda x: x != "\n", list(f.readline()))))
            if 'R' in board[-1]:
                red = (j, board[-1].index('R'))
            if 'B' in board[-1]:
                blue = (j, board[-1].index('B'))
        print(min(filter(lambda x: x != 0, solve(board, red, n, m))))
