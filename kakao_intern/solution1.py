import numpy as np
board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
moves = [1,5,3,5,1,2,1,4]
result = []
answer = 0

for move in moves:
    move -= 1
    for ele in board:
        if ele[move]:
            try:
                if result[-1] == ele[move]:
                    result.pop()
                    answer += 2
                else:
                    result.append(ele[move])
            except IndexError:
                result.append(ele[move])
            ele[move] = 0
            break
    print(np.array(board))
    print(result)

print(answer)
