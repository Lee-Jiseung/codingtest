import sys


def solution():
    n, m, w = map(int, sys.stdin.readline().split())
    roads = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]
    wormholes = [list(map(int, sys.stdin.readline().split())) for _ in range(w)]

    dp = [INF] * (n+1)
    dp[0] = 0

    for _ in range(n):
        for s, e, t in roads:
            if dp[s] != INF and dp[e] > dp[s]+t:
                dp[e] = dp[s]+t
            if dp[e] != INF and dp[s] > dp[e]+t:
                dp[s] = dp[e]+t
        for e in range(1, n + 1):
            if dp[e] > dp[0]:
                dp[e] = dp[0]
        for s, e, t in wormholes:
            if dp[s] != INF and dp[e] > dp[s]-t:
                dp[e] = dp[s]-t

    for s, e, t in roads:
        if dp[s] != INF and dp[e] > dp[s] + t:
            return "YES"
        if dp[e] != INF and dp[s] > dp[e] + t:
            return "YES"
    for s, e, t in wormholes:
        if dp[s] != INF and dp[e] > dp[s] - t:
            return "YES"
    return "NO"


INF = 2000000000
tc = int(sys.stdin.readline())
for _ in range(tc):
    print(solution())
