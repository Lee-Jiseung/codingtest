import sys


def solution():
    n = int(sys.stdin.readline())

    square_numbers = []
    numbers = [False] * (n + 1)
    i = 1
    while i*i <= n:
        square_numbers.append(i*i)
        numbers[i*i] = True
        i += 1
    if numbers[n]:
        return 1

    numbers = [False] * (n + 1)
    for num1 in square_numbers:
        for num2 in square_numbers:
            num = num1+num2
            if num == n:
                return 2
            if num > n:
                break
            numbers[num] = True

    for num in square_numbers:
        if numbers[n-num]:
            return 3
    return 4


print(solution())
