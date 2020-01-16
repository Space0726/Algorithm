import collections

class graph:
    def __init__(self, gdict=None):
        if gdict is None:
            gdict = {}
        self.gdict = gdict

def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print(start)
    for nextNode in graph[start] - visited:
        dfs(graph, nextNode, visited)
    return visited

def bfs(graph, startNode):
    seen, queue = set([startNode]), collections.deque([startNode])
    while queue:
        vertex = queue.popleft()
        print(vertex)
        for node in graph[vertex]:
            if node not in seen:
                seen.add(node)
                queue.append(node)


graph = {'a':set(['b', 'c', 'e']), 'b':set(['e']), 'c':set(['d', 'e']), 'd':set(['e']), 'e':set(['d'])}

dfs(graph, 'a')
bfs(graph, 'a')
