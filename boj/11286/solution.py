import sys
import heapq

n = int(sys.stdin.readline())
q = []
for i in range(n):
    x = int(sys.stdin.readline())
    if x == 0 and q:
        print(heapq.heappop(q)[1])
    elif x == 0:
        print(0)
    else:
        heapq.heappush(q, (abs(x), x))
