from collections import Counter
from itertools import chain
import sys
sys.stdin = open("17140_input.txt")
r, c, k = 0, 0, 0
array = []

def r_op():
    max_value = -1
    for i, r in enumerate(array):
        cnt = Counter(r)
        if 0 in cnt:
            cnt.pop(0)
        array[i] = list(chain(*sorted(cnt.items())))#, key=lambda x: x[1])))
        if max_value < len(array[i]):
            max_value = len(array[i])
    return max_value

def c_op():
    max_value = -1
    std = len(array[0])
    for i in range(std):
        print(array)
        len_arr = len(array)
        cnt = Counter([r[i] for r in array])
        if 0 in cnt:
            cnt.pop(0)
        print(cnt)
        cnt = list(chain(*sorted(cnt.items())))#, key=lambda x: x[1])))
        len_cnt = len(cnt)
        if len_arr < len_cnt:
            for _ in range(len_cnt - len_arr):
                array.append([0 for _ in range(std)])
        for r_i in range(len_cnt):
            array[r_i][i] = cnt[r_i]
        if max_value < len_arr:
            max_value = len_arr
    return max_value

def fill_zero(max_value):
    for r in array:
        len_r = len(r)
        if len_r < max_value:
            r.extend([0 for _ in range(max_value - len_r)])

for _ in range(2):
    array = []
    r, c, k = map(int, input().split())
    for i in range(3):
        array.append([int(e) for e in input().split()])

    answer = 0
    inf = 0
    while array[r][c] != k:
        max_value = -1
        print(array)
        if len(array) >= len(array[0]):
            max_value = r_op()
            fill_zero(max_value)
            print(array)
        else:
            max_value = c_op()
            print(array)
        if inf > 10:
            break
        inf += 1

    print(answer)
