import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
ladders = [-1] * 101
for _ in range(n):
    start, end = map(int, sys.stdin.readline().split())
    ladders[start] = end
snakes = [-1] * 101
for _ in range(m):
    start, end = map(int, sys.stdin.readline().split())
    snakes[start] = end

dp = [101] * 101
dq = deque()
dq.append([1, 0])
while dq:
    cur, count = dq.pop()
    if dp[cur] <= count:
        continue
    dp[cur] = count
    if cur == 100:
        continue

    for i in range(1, 7):
        next = cur + i
        if next > 100:
            break
        if ladders[next] > 0:
            next = ladders[next]
        if snakes[next] > 0:
            next = snakes[next]

        if dp[next] > count:
            dq.append([next, count+1])
print(dp[100])
