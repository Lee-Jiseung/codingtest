import sys


def star(r, c, size):
    global matrix

    if size != 3:
        new_size = size//2
        star(r+new_size, c, new_size)
        star(r, c + new_size, new_size)
        star(r+new_size, c+size, new_size)
        return

    matrix[r][c+2] = '*'
    matrix[r+1][c+1] = '*'
    matrix[r+1][c+3] = '*'
    matrix[r+2][c] = '*'
    matrix[r+2][c+1] = '*'
    matrix[r+2][c+2] = '*'
    matrix[r+2][c+3] = '*'
    matrix[r+2][c+4] = '*'


n = int(sys.stdin.readline())
matrix = [[' ' for _ in range(2*n)] for _ in range(n)]
star(0,0,n)
for row in matrix:
    print(''.join(row))
