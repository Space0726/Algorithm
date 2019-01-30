from itertools import chain, combinations
def powerset(iterable):
	xs = list(iterable)
	return chain.from_iterable(combinations(xs, n) for n in range(len(xs)+1))

def isPrime(n):
	if n < 1:
		return False
	for i in range(2, n):
		if n % i == 0:
			return False
	return True

numbers1 = "17"
numbers2 = "011"
new = list(map(lambda x: ''.join([a for a in x]), powerset(numbers2))[1:])
new = list(set(map(int, new)))
print(sum(list(map(lambda x: isPrime(int(x)), new))))
filter(lambda x: x, new)
