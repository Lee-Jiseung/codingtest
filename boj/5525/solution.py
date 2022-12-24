import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
s = input()
s += 'X'

flag = 0
indexes = []
for i, c in enumerate(s):
    if c == 'O':
        if flag == 1:
            indexes.append(i)
        flag = 0
    else:
        flag = 1

answer = 0
prev = -1234
count = 1
for index in indexes:
    if prev + 2 == index:
        count += 1
    else:
        count = 1

    if count >= n and s[index+1] == 'I':
        answer += 1
    prev = index
print(answer)
