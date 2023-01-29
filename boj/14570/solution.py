import sys

n = int(sys.stdin.readline())
tree = {i: list(map(int, sys.stdin.readline().split())) for i in range(1, n+1)}
k = int(sys.stdin.readline())

counts = [0] * (n+1)
cur = 1
while True:
    if tree[cur][0] == -1 and tree[cur][1] == -1:
        break

    if tree[cur][0] == -1 and tree[cur][1] != -1:
        cur = tree[cur][1]
    elif tree[cur][0] != -1 and tree[cur][1] == -1:
        cur = tree[cur][0]
    else:
        cur = tree[cur][0 if k%2==1 else 1]
        k = (k+1)//2
print(cur)
