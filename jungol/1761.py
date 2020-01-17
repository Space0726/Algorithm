import sys
sys.stdin = open('1761_input.txt')

from itertools import combinations as C, permutations as P

numbers = [str(nu) for nu in range(1, 10)]
def make_cases(query, strike, ball):
    cases = set()
    for strike_idx in C(range(3), int(strike)):
        for ball_idx in P(range(3), int(ball)):
            ball_set = set(ball_idx) - set(strike_idx)
            if not ball_set:
                continue
            fixed = set(strike_idx) | ball_set
            print(fixed)
    return cases

n = int(input())
answer = set()
for _ in range(n):
    if answer:
        answer &= make_cases(*input().split())
    else:
        answer = make_cases(*input().split())
print(answer)
print(len(answer))
