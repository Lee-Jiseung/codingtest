import sys
from collections import deque

n = int(sys.stdin.readline())
q = deque()
for _ in range(n):
    instr = sys.stdin.readline().split()
    if instr[0] == "push":
        q.append(instr[1])
    elif instr[0] == "front":
        if q:
            print(q[0])
        else:
            print(-1)
    elif instr[0] == "pop":
        if q:
            print(q.popleft())
        else:
            print(-1)
    elif instr[0] == "size":
        print(len(q))
    elif instr[0] == "empty":
        if q:
            print(0)
        else:
            print(1)
    else:
        if q:
            print(q[-1])
        else:
            print(-1)
