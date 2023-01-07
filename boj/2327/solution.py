import sys

h, n = map(int, sys.stdin.readline().split())
infos = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

dp = [0] * (h+1)
for hi, si in infos:
    if si < dp[h]:
        continue
        
    for i in range(h, 0, -1):
        if i-hi < 0:
            continue

        dp[i] = max(dp[i], min(dp[i-hi], si))
    dp[hi] = max(dp[hi], si)
print(dp[h])
