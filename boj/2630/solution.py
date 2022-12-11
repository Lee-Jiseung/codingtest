import sys


def color(r1, c1, r2, c2):
    global paper, answer
    flag = paper[r1][c1]
    for i in range(r1, r2):
        for j in range(c1, c2):
            if paper[i][j] != flag:
                color(r1, c1, (r1+r2)//2, (c1+c2)//2)
                color(r1, (c1+c2)//2, (r1+r2)//2, c2)
                color((r1+r2)//2, c1, r2, (c1+c2)//2)
                color((r1+r2)//2, (c1+c2)//2, r2, c2)
                return
    answer[flag] += 1


n = int(sys.stdin.readline())
paper = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
answer = {0:0, 1:0}
color(0,0,n,n)
print(answer[0])
print(answer[1])
