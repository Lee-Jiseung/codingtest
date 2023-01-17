import sys

n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
nums = sorted(nums)

if nums[0] >= 0:
    print(nums[0], nums[1])
elif nums[-1] <= 0:
    print(nums[-2], nums[-1])
else:
    minus = []
    plus = []
    zero = False
    for i in range(n):
        if nums[i] >= 0:
            if nums[i] == 0:
                zero = True
            plus.extend(nums[i:])
            break
        minus.append(nums[i])
    values = [0, 0]
    answer = 2000000001
    if zero:
        if -minus[-1] <= plus[0]:
            values = [minus[-1], 0]
            answer = -minus[-1]
        else:
            values = [0, plus[0]]
            answer = plus[0]
    if len(minus) >= 2 and -minus[-1]-minus[-2] < answer:
        answer = -minus[-1]-minus[-2]
        values = [minus[-2], minus[-1]]
    if len(plus) >= 2 and plus[0]+plus[1] < answer:
        answer = plus[0]+plus[1]
        value = [plus[0], plus[1]]
    for i, num in enumerate(minus):
        start = 0
        end = len(plus)-1
        while start < end:
            mid = (start+end)//2
            if plus[mid] >= -num:
                end = mid
            else:
                start = mid+1
        if end < len(plus):
            if answer > abs(plus[end]+num):
                answer = abs(plus[end]+num)
                values = [num, plus[end]]
        if end-1 >= 0:
            if answer > abs(plus[end-1]+num):
                answer = abs(plus[end-1]+num)
                values = [num, plus[end-1]]
    print(*values, sep=' ')
