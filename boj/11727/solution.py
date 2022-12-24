import sys

n = int(sys.stdin.readline())
count = [0, 1, 3]
while len(count) <= n:
    count.append((count[-2]*2 + count[-1]) % 10007)
print(count[n])
