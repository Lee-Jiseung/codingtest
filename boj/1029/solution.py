import sys


def func(cur, price, count, flags):
    global n, prices, dp, answer
    answer = max(answer, count)
    if dp[cur][flags] <= price:
        return
    dp[cur][flags] = price
    if count == n:
        return

    for i in range(n):
        if flags & (1<<i) or price > prices[cur][i]:
            continue

        func(i, prices[cur][i], count+1, flags | (1<<i))


n = int(sys.stdin.readline())
prices = [list(map(int, list(sys.stdin.readline().strip()))) for _ in range(n)]
answer = 0
dp = [[10 for _ in range(1<<n)] for _ in range(n)]
func(0, 0, 1, 1)
print(answer)
