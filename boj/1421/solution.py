import sys

n, c, w = map(int, sys.stdin.readline().split())
trees = [int(sys.stdin.readline()) for _ in range(n)]
answer = 0
for unit in range(1, max(trees)+1):
    temp = 0
    for tree in trees:
        temp1 = (tree // unit) * w * unit - (tree // unit) * c
        if tree % unit == 0:
            temp1 += c
        if temp1 > 0:
            temp += temp1
    answer = max(answer, temp)
print(answer)
