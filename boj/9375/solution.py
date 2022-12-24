import sys
from collections import defaultdict

t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    clothes = defaultdict(int)
    for _ in range(n):
        _, type = sys.stdin.readline().split()
        clothes[type] += 1

    answer = 1
    for v in clothes.values():
        answer *= v+1
    print(answer-1)
