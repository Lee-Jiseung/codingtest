import math
import sys
from itertools import combinations

t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    vectors = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    indexes = [i for i in range(n)]
    combi = combinations(indexes, n//2)
    answer = 100000*20*10
    x=0
    y=0
    for xi, yi in vectors:
        x += xi
        y += yi
    for minuses in combi:
        temp_x = x
        temp_y =y
        for i in minuses:
            temp_x -= 2*vectors[i][0]
            temp_y -= 2*vectors[i][1]
        answer= min(answer, math.sqrt(temp_x**2 + temp_y**2))
    print(answer)
