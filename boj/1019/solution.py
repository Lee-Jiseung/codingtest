import sys

n = int(sys.stdin.readline())
m = len(str(n))-1
dp = [[0, 1]]
for i in range(1, m):
    _, nonzero, = dp[-1]
    new_nonzero = nonzero * 10 + 10**i
    new_zero = new_nonzero
    for j in range(i+1):
        new_zero -= 10**j
    dp.append([new_zero, new_nonzero])

flag = 1
counts = [0] * 10
while m >= 0:
    e = 10 ** m
    for i in range(flag, n // e):
        counts[i] += e
    counts[n // e] += n % e + 1

    if m > 0 and flag:
        counts[0] += dp[m-1][0]
        for i in range(1, 10):
            counts[i] += dp[m-1][1]
    for i in range(10):
        counts[i] += (n // e - flag) * (e // 10) * m
    flag = 0
    n %= e
    m -= 1
print(*counts, sep=' ')
