import sys

n = int(sys.stdin.readline())
graph = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
for i in range(n):
    for j in range(n):
        if graph[i][j] == 0:
            graph[i][j] = 101

for i in range(n):
    for j in range(n):
        for k in range(n):
            graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k])

for i in range(n):
    for j in range(n):
        if graph[i][j] == 101:
            print(0, end=' ')
        else:
            print(1, end=' ')
    print()
