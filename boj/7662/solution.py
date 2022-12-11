import sys
import heapq
from collections import defaultdict

t = int(sys.stdin.readline())
for _ in range(t):
    k = int(sys.stdin.readline())
    q = defaultdict(int)
    for _ in range(k):
        instr, n = sys.stdin.readline().split()
        if instr == 'I':
            q[int(n)] += 1
        elif not q:
            continue
        elif n == '-1':
            mn = min(q.keys())
            q[mn] -= 1
            if q[mn] == 0:
                del q[mn]
        else:
            mx = max(q.keys())
            q[mx] -= 1
            if q[mx] == 0:
                del q[mx]

    if q:
        print(max(q.keys()), min(q.keys()))
    else:
        print('EMPTY')
