import sys

n, m = map(int, sys.stdin.readline().split())
grid = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

sum_grid = [[0 for _ in range(n+1)] for _ in range(n+1)]
for i in range(n):
    for j in range(n):
        sum_grid[i+1][j+1] = sum_grid[i+1][j] + grid[i][j]

for j in range(1, n+1):
    for i in range(1, n+1):
        sum_grid[i][j] += sum_grid[i-1][j]

for _ in range(m):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    print(sum_grid[x2][y2]-sum_grid[x2][y1-1]-sum_grid[x1-1][y2]+sum_grid[x1-1][y1-1])
