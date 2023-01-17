import sys


def palindrome(start, end):
    global nums, is_palindrome, n

    if is_palindrome[start][end] != -1:
        return is_palindrome[start][end]

    if (start+end)%2 == 0:
        left = (start+end) // 2
        right = (start+end) // 2
    else:
        left = (start + end) // 2
        right = (start + end) // 2 + 1

    while start <= left:
        if is_palindrome[left][right] == 1:
            left -= 1
            right += 1
        elif is_palindrome[left][right] == -1 and nums[left] == nums[right]:
            is_palindrome[left][right] = 1
            left -= 1
            right += 1
        else:
            while 0 <= left and right < n:
                is_palindrome[left][right] = 0
                left -= 1
                right += 1
            return 0
    is_palindrome[start][end] = 1
    return 1


n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
is_palindrome = [[-1 for _ in range(n)] for _ in range(n)]
for i in range(n):
    is_palindrome[i][i] = 1
for _ in range(m):
    s, e = map(int, sys.stdin.readline().split())
    print(palindrome(s-1, e-1))
