import sys
from itertools import product


def solution():
    n = int(sys.stdin.readline())
    length = len(str(n))

    m = int(sys.stdin.readline())
    buttons = [i for i in range(10)]
    if m > 0:
        malfunctions = list(map(int, sys.stdin.readline().split()))
        for malfunction in malfunctions:
            buttons.remove(malfunction)

    answer = abs(n - 100)
    if m == 10:
        print(answer)
        return
    
    if length > 1:
        answer = min(answer, abs(int(''.join(map(str, [buttons[-1]]*(length-1))))-n)+length-1)

    if buttons[0] != 0:
        answer = min(answer, abs(int(''.join(map(str, [buttons[0]]*(length+1))))-n)+length+1)
    elif len(buttons) >= 2:
        answer = min(answer, abs(int(''.join(map(str, [buttons[1]]+[buttons[0]] * length))) - n)+length+1)

    nums = product(buttons, repeat=length)
    for num in nums:
        answer = min(answer, abs(int(''.join(map(str, num)))-n)+length)
    print(answer)

solution()
