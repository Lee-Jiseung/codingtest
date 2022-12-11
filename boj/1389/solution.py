import sys

INF = 101

n, m = map(int, sys.stdin.readline().split())
graph = [[INF for _ in range(n)] for _ in range(n)]
for i in range(n):
    graph[i][i] = 0
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    a -= 1
    b -= 1
    graph[a][b] = 1
    graph[b][a] = 1

for k in range(n):
    for i in range(n):
        for j in range(n):
            if graph[i][j] > graph[i][k] + graph[k][j]:
                graph[i][j] = graph[i][k]+graph[k][j]

min_sum = INF * n + 1
min_num = 0
for i in range(n):
    steps = sum(graph[i])
    if steps < min_sum:
        min_sum = steps
        min_num = i

print(min_num+1)
