import sys
import heapq

n, k = map(int, sys.stdin.readline().split())
dp = [100_001] * 200_000

hq = []
heapq.heappush(hq, (0, n))
dp[n] = 0

while hq:
    time, location = heapq.heappop(hq)
    if dp[location] < time:
        continue
    if location == k:
        continue
    
    if location * 2 < 200_000 and dp[location*2] > time:
        dp[location*2] = time
        heapq.heappush(hq, (time, location*2))

    if location + 1 < 200_000 and dp[location + 1] > time:
        dp[location+1] = time+1
        heapq.heappush(hq, (time+1, location + 1))
    if location - 1 >= 0 and dp[location - 1] > time:
        dp[location-1] = time+1
        heapq.heappush(hq, (time+1, location - 1))
        
print(dp[k])
