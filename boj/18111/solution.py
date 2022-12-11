import sys

n, m, b = map(int, sys.stdin.readline().split())
heights = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

count = [0] * 257
for height in heights:
    for h in height:
        count[h] += 1

answer_height = 0
answer = n*m*257*2
for i in range(257):
    remove_count = 0
    for j in range(i+1, 257):
        remove_count += (j-i) * count[j]
    put_count = 0
    for j in range(i):
        put_count += (i-j) * count[j]

    if remove_count + b >= put_count:
        time = remove_count * 2 + put_count
        if answer >= time:
            answer = time
            answer_height = i

print(answer, answer_height)
