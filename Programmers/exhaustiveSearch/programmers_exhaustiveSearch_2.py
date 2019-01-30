from itertools import permutations
'''
numbers1 = "17"
numbers2 = "011"
numbers3 = "5234901"
'''
def subset(li):
	result = []
	for i in range(1, len(li) + 1):
		result.extend(permutations(li,i))
	return result

def isPrime(n):
	if n < 2:
		return False
	for i in range(2, n):
		if n % i == 0:
			return False
	return True

def solution(numbers):
	new = list(map(lambda x: ''.join([a for a in x]), subset(numbers)))
	new = list(set(map(int, new)))
	return sum(list(map(lambda x: isPrime(int(x)), new)))
