import sys

n = int(sys.stdin.readline())
nodes = [[] for _ in range(n)]
for _ in range(n):
    cur, left, right = map(lambda x: int(x)-1, sys.stdin.readline().split())
    nodes[cur] = [left, right]

root = [True] * n
for left, right in nodes:
    if left != -2:
        root[left] = False
    if right != -2:
        root[right] = False

root_node = root.index(True)

cols = [-1] * n
rows = [-1] * n
stack = [[root_node, 0]]
count = 0
while stack:
    print(stack)
    cur, row = stack.pop()
    if cur == -2:
        continue
    rows[cur] = row

    left, right = nodes[cur]

    if left == -2 and right == -2:
        cols[cur] = count
        count += 1
        continue

    if left == -2 or cols[left] >= 0:
        cols[cur] = count
        count += 1
        if left == -2:
            stack.append([right, row+1])
        continue

    stack.extend([[right, row+1], [cur, row], [left, row+1]])

print(cols)
print(sorted(cols))
print(rows)

candidates = [[10001, -1] for _ in range(max(rows)+1)]
for i in range(n):
    candidates[rows[i]][0] = min(cols[i], candidates[rows[i]][0])
    candidates[rows[i]][1] = max(cols[i], candidates[rows[i]][1])
print(candidates)

max_diff = 0
max_row = 0
for i, candidate in enumerate(candidates):
    diff = candidate[1] - candidate[0]
    if diff > max_diff:
        max_diff = diff
        max_row = i
print(max_row+1, max_diff+1)