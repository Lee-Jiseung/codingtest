import sys
import heapq


def dijkstra(start, end):
    global roads, n
    dist = [INF] * n
    dist[start] = 0
    hq = []
    heapq.heappush(hq, [0, start])
    visited = [False] * n
    while hq:
        time, cur = heapq.heappop(hq)
        if visited[cur]:
            continue
        if cur == end:
            return time
        visited[cur] = True

        for e, t in roads[cur]:
            if visited[e]:
                continue
            if dist[e] > dist[cur]+t:
                dist[e] = dist[cur]+t
                heapq.heappush(hq, [dist[cur]+t, e])


n, m, x = map(int, sys.stdin.readline().split())
roads = [[] for _ in range(n)]
for _ in range(m):
    start, end, ti = map(int, sys.stdin.readline().split())
    roads[start-1].append([end-1, ti])

INF = 1000*100*10
answer = 0
for i in range(n):
    answer = max(answer, dijkstra(i, x-1)+dijkstra(x-1, i))
print(answer)
