import sys
from collections import deque

v = int(sys.stdin.readline())
edge_infos = [list(map(int, sys.stdin.readline().split())) for _ in range(v)]

tree = {i:{} for i in range(1, v+1)}
for edge_info in edge_infos:
    for i in range(1, len(edge_info)-1, 2):
        tree[edge_info[0]][edge_info[i]] = edge_info[i+1]

root_node = 1

dq = deque()
dq.append([root_node, 0])
visited = [False] * (v+1)
depths = []
while dq:
    cur, d = dq.popleft()

    if len(depths) < d+1:
        depths.append([cur])
    else:
        depths[d].append(cur)
    visited[cur] = True

    for node in tree[cur].keys():
        if visited[node]:
            continue
        dq.append([node, d+1])

dist = [0] * (v+1)
visited = [False] * (v+1)
answer = 0
for i in range(len(depths)-1, -1, -1):
    for cur in depths[i]:
        for node, weight in tree[cur].items():
            if visited[node]:
                continue

            answer = max(answer, dist[node] + dist[cur] + weight)
            dist[node] = max(dist[node], dist[cur] + weight)
        visited[cur] = True

print(answer)
