import sys


def solution():
    n, m, w = map(int, sys.stdin.readline().split())
    roads = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]
    wormholes = [list(map(int, sys.stdin.readline().split())) for _ in range(w)]

    for start in range(1, n+1):
        dp = [INF] * (n+1)
        dp[start] = 0
        
        for _ in range(n-1):
            update = False
            for s, e, t in roads:
                if dp[s] != INF and dp[e] > dp[s]+t:
                    dp[e] = dp[s]+t
                    update = True
                if dp[e] != INF and dp[s] > dp[e]+t:
                    dp[s] = dp[e]+t
                    update = True
            for s, e, t in wormholes:
                if dp[s] != INF and dp[e] > dp[s]-t:
                    dp[e] = dp[s]-t
                    update = True
            
            if not update:
                break

        for s, e, t in roads:
            if dp[s] != INF and dp[e] > dp[s] + t:
                return "YES"
            if dp[e] != INF and dp[s] > dp[e] + t:
                return "YES"
        for s, e, t in wormholes:
            if dp[s] != INF and dp[e] > dp[s] - t:
                return "YES"
    return "NO"


INF = 2500*10000*100
tc = int(sys.stdin.readline())
for _ in range(tc):
    print(solution())
