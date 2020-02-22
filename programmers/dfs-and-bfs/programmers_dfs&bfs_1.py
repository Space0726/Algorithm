'''
result = 0

def dfs(numbers, target, k):
    if k == len(numbers):
        if sum(numbers) == target:
            global result
            result += 1
    else:
        numbers[k] *= 1
        dfs(numbers, target, k+1)
        numbers[k] *= -1
        dfs(numbers, target, k+1)

def first_solution(numbers, target):
    dfs(n, target, 0)
    return result
'''
def solution(numbers, target):
    if not numbers and target == 0:
        return 1
    elif not numbers:
        return 0
    else:
        return solution(numbers[1:], target - numbers[0]) + solution(numbers[1:], target + numbers[0])
