import functools
import collections
'''
import itertools

clothes = [['a', 'headgear'], ['b', 'eyewear'], ['c', 'headgear']]

def first_solution(clothes):
    answer = 0
    a = collections.Counter(dict(clothes).values()).values()
    for i in range(len(a)):
        answer += sum(map(lambda x: functools.reduce(lambda y, z: y*z: x), itertools.combinations(a, i+1)))
    return answer
'''

def solution(clothes):
    answer = 0
    a = list(map(lambda x: x + 1, collections.Counter(dict(clothes).values()).values()))
    if len(a) == 1:
        return list(a)[0] - 1
    return functools.reduce(lambda x, y: x * y, a) - 1
