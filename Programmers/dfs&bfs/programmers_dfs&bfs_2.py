def dfs(graph, start):
	visited = []
	stack = [start]
	while stack:
		n = stack.pop()
		if n not in visited:
			visited.append(n)
			stack += set(graph[n]) - set(visited)
	return visited

def solution(n, computers):
	linked = []
	num = 0
	graph = dict(enumerate(range(n)))
	for i in range(n):
		graph[i] = [idx for idx, v in enumerate(computers[i]) if v == 1 and idx != i]	
	for i in range(n):
		if i in linked:
			continue
		linked.extend(dfs(graph, i))
		num += 1
	return num

'''
computers = [[1,1,0],[1,1,1],[0,1,1]]
n = 3
print(solution(n, computers))
'''
