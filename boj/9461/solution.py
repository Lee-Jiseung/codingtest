import sys

t = int(sys.stdin.readline())
p = [0,1,1,1]
for _ in range(t):
    n = int(sys.stdin.readline())
    while len(p) <= n:
        p.append(p[-3]+p[-2])
    print(p[n])
