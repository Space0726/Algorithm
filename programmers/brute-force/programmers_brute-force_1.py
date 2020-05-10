'''
def first_solution(answers):
    m = [[1,2,3,4,5], [2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5]]
    a = []
    for i in range(3):
        if len(answers) > len(m[i]):
            m[i] *= (len(answers) // len(m[i])) + 1
        a.append(sum(map(lambda x: 1 if x[0] == x[1] else 0, zip(answers, m[i]))))
    return [i + 1 for i, x in enumerate(a) if x == max(a)]
'''

def solution(answers):
    m = [[1, 2, 3, 4, 5],
         [2, 1, 2, 3, 2, 4, 2, 5],
         [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
    result = [0, 0, 0]
    for i in range(3):
        for idx, a in enumerate(answers):
            if m[i][idx % len(m[i])] == a:
                result[i] += 1
    return [idx + 1 for idx, a in enumerate(result) if a == max(result)]
