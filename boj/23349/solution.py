import sys
from collections import defaultdict

n = int(sys.stdin.readline())
submits = [sys.stdin.readline().split() for _ in range(n)]
table = defaultdict(int)
names = defaultdict(int)
for name, place, start, end in submits:
    if names[name] > 0:
        continue
    names[name] = 1
    for time in range(int(start), int(end)):
        table[(place, time)] += 1
max_count = 0
sections = []
for (place, time), count in table.items():
    if count > max_count:
        max_count = count
        sections = [(place, time)]
    elif count == max_count:
        sections.append((place, time))
sections = sorted(sections, key=lambda x: (x[0], x[1]))
answer = list(sections[0])
answer.append(answer[-1]+1)
for i in range(1, len(sections)):
    if sections[i][0] != answer[0]:
        break
    if answer[-1] == sections[i][1]:
        answer[-1] += 1
    else:
        break
print(answer[0], str(answer[1]), str(answer[2]))
