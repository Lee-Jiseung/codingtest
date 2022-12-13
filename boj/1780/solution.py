import sys


def divide(r, c, l):
    global paper, counts
    for i in range(r, r+l):
        for j in range(c, c+l):
            if paper[i][j] != paper[r][c]:
                newl = l//3
                divide(r, c, newl)
                divide(r+newl, c, newl)
                divide(r+newl*2, c, newl)
                divide(r, c+newl, newl)
                divide(r+newl, c+newl, newl)
                divide(r+newl*2, c+newl, newl)
                divide(r, c+newl*2, newl)
                divide(r+newl, c+newl*2, newl)
                divide(r+newl*2, c+newl*2, newl)
                return
    counts[paper[r][c]] += 1


n = int(sys.stdin.readline())
paper = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
counts = {-1:0, 0:0, 1:0}
divide(0, 0, n)
print(counts[-1])
print(counts[0])
print(counts[1])
