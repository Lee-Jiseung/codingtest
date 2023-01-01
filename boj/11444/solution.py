from collections import defaultdict


def solution(n):
    global mod, dp
    if n == 0:
        return 0
    if n == 1:
        return 1
    if dp[n] > 0:
        return dp[n]

    if n%2 == 0:
        k = n // 2
        fibonacci = (solution(k) * (solution(k) + 2 * solution(k-1))) % mod
    else:
        k = (n+1) // 2
        fibonacci = (solution(k)**2 + solution(k-1)**2) % mod
    dp[n] = fibonacci
    return fibonacci


mod = 1000000007
dp = defaultdict(int)
n = int(input())
answer = solution(n)
print(answer)
