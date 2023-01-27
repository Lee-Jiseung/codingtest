import sys
from itertools import permutations


def func(rcs):
    global matrix
    r, c, s = rcs
    for si in range(1, s+1):
        top = r-si-1
        bottom = r+si-1
        left = c-si-1
        right = c+si-1
        top_left = matrix[top][left]
        for i in range(top, bottom):
            matrix[i][left] = matrix[i+1][left]
        for j in range(left, right):
            matrix[bottom][j] = matrix[bottom][j+1]
        for i in range(bottom, top, -1):
            matrix[i][right] = matrix[i-1][right]
        for j in range(right, left, -1):
            matrix[top][j] = matrix[top][j-1]
        matrix[top][left+1] = top_left


n, m, k = map(int, sys.stdin.readline().split())
original = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
ops = [list(map(int, sys.stdin.readline().split())) for _ in range(k)]
indexes = [i for i in range(k)]
permu = permutations(indexes, k)
answer = 100*50+1
for seq in permu:
    matrix = [row[:] for row in original]
    for i in seq:
        func(ops[i])
    answer = min(answer, min(list(map(lambda x: sum(x), matrix))))
print(answer)
