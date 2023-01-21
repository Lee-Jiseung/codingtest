import sys

str1 = sys.stdin.readline().strip()
bomb = sys.stdin.readline().strip()
m = len(bomb)
stack = []
for c in str1:
    stack.append(c)
    if len(stack) >= m:
        if bomb == ''.join(stack[len(stack)-m:]):
            for _ in range(m):
                stack.pop()
if stack:
    print(''.join(stack))
else:
    print("FRULA")
