import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
INF = 100*100000*10
graph = [[INF for _ in range(n)] for _ in range(n)]
for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a-1][b-1] = min(graph[a-1][b-1], c)
for i in range(n):
    graph[i][i] = 0

for i in range(n):
    for j in range(n):
        for k in range(n):
            graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k])

for i in range(n):
    for j in range(n):
        print(0 if graph[i][j] == INF else graph[i][j], end=' ')
    print()
