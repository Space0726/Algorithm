import numpy as np

key = np.array([[0,1,0],[1,0,0],[1,0,0]])
lock = np.array([[1,1,1],[1,1,0],[1,0,1]])

*rect, = 0, 0, 0, 0
for i in range(len(lock)):
    if any(lock[i] == 0):
        rect[0] = i
        break
for i in range(len(lock)-1, -1, -1):
    if any(lock[i] == 0):
        rect[1] = i
        break
for i in range(len(lock)):
    if any(lock[:, i] == 0):
        rect[2] = i
        break
for i in range(len(lock)-1, -1, -1):
    if any(lock[:, i] == 0):
        rect[3] = i
        break

print(rect)
start, end = (rect[0], rect[2]), (rect[1], rect[3])
pattern = lock[rect[0]:rect[1]+1, rect[2]:rect[3]+1] == False
print(pattern)
for i in range(len(key) - len(pattern) + 1):
    for j in range(len(key) - len(pattern) + 1):
        compare = key[i:len(pattern)+i, j:j+len(pattern)] == True
        if (compare == pattern).all():
            print(key[i:len(pattern)+i, j:j+len(pattern)])
            print(pattern)
print(pattern == key)