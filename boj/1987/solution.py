import sys
from collections import defaultdict

def func(x, y, count):
    global board, flags, answer, dr, dc, max_count, visited
    
    answer = max(answer, count)
    if answer == max_count:
        return
    if visited[x][y][flags] >= count:
        return
    visited[x][y][flags] = count

    for dri, dci in zip(dr, dc):
        newx = x + dri
        newy = y + dci

        if newx < 0 or newx >= r or newy < 0 or newy >= c:
            continue
        if flags & 1 << board[newx][newy]:
            continue
        flags |= 1 << board[newx][newy]
        func(newx, newy, count + 1)
        flags ^= 1 << board[newx][newy]


r, c= map(int, sys.stdin.readline().split())
board = [sys.stdin.readline().strip() for _ in range(r)]
new_board = [[0 for _ in range(c)] for _ in range(r)]
A = ord('A')
exist = [False]*26
for i in range(r):
    for j in range(c):
        new_board[i][j] = ord(board[i][j]) - A
        exist[ord(board[i][j]) - A] = True
max_count = exist.count(True)
board = new_board
dr = [-1, 0, 1, 0]
dc = [0, -1, 0, 1]
answer = 0
flags = 0
flags |= 1 << board[0][0]
visited = [[defaultdict(int) for _ in range(c)] for _ in range(r)]
func(0,0,1)
print(answer)
