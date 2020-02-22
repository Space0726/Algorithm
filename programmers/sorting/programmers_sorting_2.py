import functools

numbers1 = [6, 10, 2]
numbers2 = [3, 30, 34, 5, 9]
numbers3 = [325, 254, 6632345, 1, 32544, 30, 6, 33333]
'''
l = len(str(max(numbers3)))
numbers3.sort(key=lambda x: (str(x)*((l // len(str(x))) + 1))[:l], reverse=True)
print(numbers3)
print(functools.reduce(lambda x, y:str(x) + str(y), numbers3))
print(str(int(''.join(map(str, numbers3)))))
'''

def solution(numbers):
    maxLength = len(str(max(numbers)))
    numbers.sort(key=lambda x: (str(x)*((maxLength // len(str(x))) + 1))[:maxLength], reverse=True)
    answer = functools.reduce(lambda x, y: str(x) + str(y), numbers)
    # The following is also possible, but the excution speed is slower than the above case.
    # answer = str(int(''.join(map(str, numbers))))
    return answer if int(answer) else '0'
