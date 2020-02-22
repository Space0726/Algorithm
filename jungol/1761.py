class Query:
    def __init__(self, numbers, strike, ball):
        self.numbers = tuple(map(int, numbers))
        self.strike = int(strike)
        self.ball = int(ball)


def check_strike(digits, query):
    strike = 0
    for i in range(3):
        if digits[i] == query.numbers[i]:
            strike += 1
    return strike == query.strike

def check_ball(digits, query):
    ball = 0
    for i in range(3):
        for j in range(3):
            if i == j:
                continue
            if digits[i] == query.numbers[j]:
                ball += 1
    return ball == query.ball

queries = []
answer = 0
n = int(input())
for _ in range(n):
    queries.append(Query(*input().split()))
for check in range(123, 1000):
    digits = check//100, check%100//10, check%10
    check_cnt = -len(queries)
    if 0 in digits:
        continue
    if digits[0] != digits[1] and digits[1] != digits[2] and digits[0] != digits[2]:
        for query in queries:
            if check_strike(digits, query) and check_ball(digits, query):
                check_cnt += 1
        if not check_cnt:
            answer += 1
print(answer)
