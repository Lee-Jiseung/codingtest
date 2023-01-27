import sys
from collections import deque

n = int(sys.stdin.readline())
a, b = map(int, sys.stdin.readline().split())
m = int(sys.stdin.readline())
relationships = [[] for _ in range(n)]
for _ in range(m):
    x, y = map(int, sys.stdin.readline().split())
    relationships[x-1].append(y-1)
    relationships[y-1].append(x-1)
dq = deque()
dq.append([a-1, 0])
visited = [False] * n
answer = -1
while dq:
    cur, count = dq.popleft()
    if visited[cur]:
        continue
    if cur == b-1:
        answer = count
        break
    visited[cur] = True

    for next in relationships[cur]:
        dq.append([next, count+1])
print(answer)
