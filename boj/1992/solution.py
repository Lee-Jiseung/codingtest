import sys


def divide(r, c, l):
    global image, answer

    newl = l // 2
    if newl == 0:
        return image[r][c]

    left_top = divide(r, c, newl)
    right_top = divide(r, c + newl, newl)
    left_bottom = divide(r + newl, c, newl)
    right_bottom = divide(r + newl, c + newl, newl)

    if left_top == right_top == left_bottom == right_bottom and len(left_top) == 1:
        return left_top
    return '('+left_top+right_top+left_bottom+right_bottom+')'


n = int(sys.stdin.readline())
image = [sys.stdin.readline() for _ in range(n)]
print(divide(0, 0, n))
