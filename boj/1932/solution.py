import sys

n = int(sys.stdin.readline())
triangle = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

for i in range(1, n):
    for j in range(len(triangle[i])):
        max_sum = -1
        if j-1 >= 0:
            max_sum = max(max_sum, triangle[i-1][j-1])
        if j < len(triangle[i-1]):
            max_sum = max(max_sum, triangle[i-1][j])
        triangle[i][j] += max_sum
print(max(triangle[n-1]))
