import sys

nums = ["" for _ in range(4)]
for _ in range(5):
    line = sys.stdin.readline().strip().split()
    for i, l in enumerate(line):
        nums[i] += l
correct_nums = [
    [4,7,10],
    [0,1,3,4,6,7,9,10,12,13],
    [3,4,10,11],
    [3,4,9,10],
    [1,4,9,10,12,13],
    [4,5,9,10],
    [4,5,10],
    [3,4,6,7,9,10,12,13],
    [4,10],
    [4,9,10]
]
answer = []
for num in nums:
    for j in range(10):
        flag = True
        for index in correct_nums[j]:
            if num[index] == '#':
                flag = False
                break
        if flag:
            answer.append(str(j))
            break
answer.insert(2,':')
print(''.join(answer))

