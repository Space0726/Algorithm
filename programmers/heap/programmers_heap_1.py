from heapq import heappush, heapify
def solution(scoville, K):
    result = 0
    heap = []
    for s in scoville:
        heappush(heap,(-s,  s))
    print(heap)
    while min(dict(heap).values()) < K:
        if len(heap) < 2:
            return -1
        a = heap.pop()
        b = heap.pop()
        v = a[1] + b[1]*2
        heappush(heap, (-v, v))
        result += 1
    return result

print(solution([1,2,3,9,10,12], 7))
'''
l = [1,2,3,9,10,12]
k = 7
heap = []
for i in l:
    heappush(heap, i)
print(heap)
heapify(l)
l.sort()
print(l)
'''
