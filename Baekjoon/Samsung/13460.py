def moveBead(board, red, blue, goal, direction, count=0):
    redStop = False
    blueStop = False
    redEnd = False
    blueEnd = False
    while (not redStop) or (not blueStop):
        if direction == 'U':
            if not redEnd and board[red[0]-1][red[1]] == '#':
                redStop = True
            else:
                if board[red[0]-1][red[1]] == 'B' and board[blue[0]-1][blue[1]] == '#':
                    blueStop = True
                    redStop = True
                else:
                    red[0] -= 1
            if not blueEnd and board[blue[0]-1][blue[1]] == '#':
                blueStop = True
            else:
                if board[blue[0]-1][blue[1]] == 'A' and board[red[0]-1][red[1]] == '#':
                    blueStop = True
                    redStop = True
                else:
                    blue[0] -= 1
        if board[red[0]][red[1]] == 'O':
            redEnd = True
        if board[blue[0]][blue[1]] == 'O':
            blueEnd = True
        if count > 10 or (redEnd and blueEnd) or ((not redEnd) and blueEnd):
            return -1
        elif redEnd and not blueEnd:
            return count
        else:
            if blueStop and redStop:
                return 0

    print('!',red, blue)
            

with open("13460_input.txt") as f:
    for i in range(7):
        n, m = map(int, f.readline().split())
        board = []
        blue = []
        red = []
        goal = []
        for j in range(n):
            board.append(list(f.readline())[:-1])
            if 'R' in board[-1]:
                red = [j, board[-1].index('R')]
            if 'B' in board[-1]:
                blue = [j, board[-1].index('B')]
            if 'O' in board[-1]:
                goal = [j, board[-1].index('O')]
        moveBead(board, red, blue, goal, 'U')
