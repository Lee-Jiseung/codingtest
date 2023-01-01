import sys
from collections import deque

n = int(sys.stdin.readline())
edges = {i:[] for i in range(1, n+1)}
for _ in range(n-1):
    a, b = map(int, sys.stdin.readline().split())
    edges[a].append(b)
    edges[b].append(a)

dq = deque()
dq.append(1)
visited = [False] * (n+1)
parent = [-1] * (n+1)
while dq:
    cur = dq.popleft()
    if visited[cur]:
        continue
    visited[cur] = True

    for node in edges[cur]:
        if visited[node]:
            continue
        parent[node] = cur
        dq.append(node)

for i in range(2, n+1):
    print(parent[i])
