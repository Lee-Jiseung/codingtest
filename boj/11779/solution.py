import sys
import heapq

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
buses = [[] for _ in range(n+1)]
for _ in range(m):
    s,e,c = map(int, sys.stdin.readline().split())
    buses[s].append([e,c])
start, end = map(int, sys.stdin.readline().split())

INF = 1000*100000*10
dist = [INF] * (n+1)
dist[start] = 0
visited = [False]*(n+1)
hq = []
heapq.heappush(hq, [0, start, [start]])
while hq:
    cost, cur, path = heapq.heappop(hq)
    if visited[cur]:
        continue
    if cur == end:
        print(cost)
        print(len(path))
        print(' '.join(map(str, path)))
        break
    visited[cur] = True

    flag = True
    for e, c in buses[cur]:
        if visited[e]:
            continue
        new_cost = cost + c
        if dist[e] > new_cost:
            dist[e] = new_cost
            if flag:
                path.append(e)
                flag = False
            else:
                path[-1] = e
            heapq.heappush(hq, [new_cost, e, path.copy()])
