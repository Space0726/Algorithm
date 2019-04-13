# Input board's state, red and blue position
def solve(board, red, blue):

    # To facilitate movement, remove 'R' and 'B' at board
    board[red[0]][red[1]] = '.'
    board[blue[0]][blue[1]] = '.'

    # Make dictionary (key = move count(int), value = start point(set - To remove duplicate))
    dict_ = dict([[i,set()] for i in range(10)])

    # Add red, blue start point
    dict_[0].add((red, blue))
    moves = [(-1,0), (1,0), (0,-1), (0,1)]

    # If it can't return anything until move count 10, return -1
    for i in range(10):

        # Repeat until move count's start points are disappeared.
        while dict_[i]:
            r, b = dict_[i].pop()

            # Move first all direction and check if it wall('#') or end point('O')
            for j in range(4):
                rx, ry = r[0]+moves[j][0], r[1]+moves[j][1]
                bx, by = b[0]+moves[j][0], b[1]+moves[j][1]

                # Marks the flag as False when red or blue is encountered except for '.'
                rFlag, bFlag = True, True

                # If 'R' and 'B' points are same, one of them must move back
                # Variable 'isRedLong' determines the point to be moved.
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

                # If blue meets 'O' first than red, go to next loop
                # If red and blue meet 'O' together, also go to next loop
                if board[bx][by] == 'O':
                    continue
                
                # If red meets 'O' but blue doesn't meet 'O', end loop and return move count
                if board[rx][ry] == 'O':
                    return i+1
                
                # Move to the original place
                rx -= moves[j][0]
                ry -= moves[j][1]
                bx -= moves[j][0]
                by -= moves[j][1]

                # If red and blue is same position, one of them is move back.
                if rx == bx and ry == by:
                    if isRedLong:
                        rx -= moves[j][0]
                        ry -= moves[j][1]
                    else:
                        bx -= moves[j][0]
                        by -= moves[j][1]

                # If move count is 10 but not return anything, go to next loop 
                if i == 9:
                    continue

                # Add next move count's start point
                dict_[i+1].add(((rx,ry),(bx,by)))
    return -1


with open("13460_input.txt") as f:
    for i in range(7):
        n, m = map(int, f.readline().rstrip().split())
        board = []
        for j in range(n):
            board.append(list(f.readline().rstrip()))
            if 'R' in board[-1]:
                red = (j, board[-1].index('R'))
            if 'B' in board[-1]:
                blue = (j, board[-1].index('B'))
        print(solve(board, red, blue))
