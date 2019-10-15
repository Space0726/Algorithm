import itertools
import numpy as np

def shorten(k, maps, routes, answer):
    for kcnt in range(k):
        for m in range(len(maps)):
            for i in range(len(maps[m])):
                sm = maps[:]
                sm[m][i] -= kcnt+1
                for r in routes:
                    if (m-1, i) in r:
                        findRoute(sm, m, i, routes, routes.index(r), r.index((m-1, i)), answer)
                    if (m+1, i) in r:
                        findRoute(sm, m, i, routes, routes.index(r), r.index((m+1, i)), answer)
                    if (m, i-1) in r:
                        findRoute(sm, m, i, routes, routes.index(r), r.index((m, i-1)), answer)
                    if (m, i+1) in r:
                        findRoute(sm, m, i, routes, routes.index(r), r.index((m, i+1)), answer)

def findRoute(maps, x, y, routes, ri, depth, answer):
    cnt = -4
    if len(maps)-1 > x and maps[x][y] > maps[x+1][y]:
        routes.append(routes[ri][:])
        routes[-1].append((x+1,y))
        findRoute(maps, x+1, y, routes, len(routes)-1, depth+1, answer)
    else:
        cnt += 1
    if x and maps[x][y] > maps[x-1][y]:
        routes.append(routes[ri][:])
        routes[-1].append((x-1,y))
        findRoute(maps, x-1, y, routes, len(routes)-1, depth+1, answer)
    else:
        cnt += 1
    if len(maps)-1 > y and maps[x][y] > maps[x][y+1]:
        routes.append(routes[ri][:])
        routes[-1].append((x,y+1))
        findRoute(maps, x, y+1, routes, len(routes)-1, depth+1, answer)
    else:
        cnt += 1
    if y and maps[x][y] > maps[x][y-1]:
        routes.append(routes[ri][:])
        routes[-1].append((x,y-1))
        findRoute(maps, x, y-1, routes, len(routes)-1, depth+1, answer)
    else:
        cnt += 1
    if not cnt:
        if answer[0] < depth:
            answer[0] = depth
    else:
        routes.remove(routes[ri])

def solve(n, k, maps):
    answer = [0]
    routes = []
    tmp = list(itertools.chain(*maps))
    summit = max(tmp)
    starts = []
    for i in range(len(tmp)):
        if summit == tmp[i]:
            starts.append((i // n, i % n))
    for x, y in starts:
        routes.append([(x, y)])
        findRoute(maps, x, y, routes, len(routes)-1, 1, answer)
    shorten(k, maps, routes, answer)
    print(routes)
    return answer[0]

with open("1949_input.txt") as f:
    cases = int(f.readline())
    for i in range(cases):
        t = list(map(int, f.readline().split()))
        maps = []
        for j in range(t[0]):
            maps.append(list(map(int, f.readline().split())))
        print(f'#{i+1} {solve(t[0], t[1], maps)}')
        print(np.array(maps))
