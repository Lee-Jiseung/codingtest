import sys

n, k = map(int, sys.stdin.readline().split())
answer = 1
for i in range(k):
    answer *= n-i
for i in range(k):
    answer //= i+1
print(answer)
