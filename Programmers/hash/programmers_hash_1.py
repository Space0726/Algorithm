import collections
'''
p = ['a', 'b', 'c']
t = ['a', 'b']
'''
def solution(participant, completion):
	return list(collections.Counter(participant) - collections.Counter(completion))[0]
