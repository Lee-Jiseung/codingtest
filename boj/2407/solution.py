import sys

n, m = map(int, sys.stdin.readline().split())
answer = 1
for i in range(m):
    answer *= n-i
for i in range(1, m+1):
    answer //= i
print(answer)
