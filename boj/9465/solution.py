import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
    n = int(sys.stdin.readline())
    scores = [list(map(int, sys.stdin.readline().split())) for _ in range(2)]

    dp = [[0 for _ in range(n)] for _ in range(3)]
    dp[0][0] = scores[0][0]
    dp[1][0] = scores[1][0]
    for i in range(1, n):
        dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + scores[0][i]
        dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + scores[1][i]
        dp[2][i] = max(dp[0][i-1], dp[1][i-1], dp[2][i-1])

    print(max(dp[0][n-1], dp[1][n-1], dp[2][n-1]))
