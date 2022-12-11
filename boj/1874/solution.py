import sys


def solution():
    n = int(sys.stdin.readline())
    nums = [int(sys.stdin.readline()) for _ in range(n)]
    cur = 1
    stack = []
    answer = []
    for num in nums:
        if cur <= num:
            while cur != num:
                stack.append(cur)
                cur += 1
                answer.append('+')
            cur += 1
            answer.append('+')
            answer.append('-')
        else:
            if stack[-1] == num:
                stack.pop()
                answer.append('-')
            else:
                print('NO')
                return
    print(*answer, sep='\n')


solution()
