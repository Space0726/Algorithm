'''
priorities1 = [2, 1, 3, 2]
location1 = 2
priorities2 = [1, 1, 9, 1, 1, 1]
location2 = 0
'''
def solution(priorities, location):
	p = list(enumerate(priorities))
	result = 0
	while p:
		v = p.pop(0)
		if not p:
			return result + 1
		if max(dict(p).values()) > v[1]:
			p.append(v)
		else:
			result += 1
			if v[0] == location:
				return result
