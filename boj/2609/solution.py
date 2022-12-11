import sys

a, b = map(int, sys.stdin.readline().split())
if a > b:
    a, b = b, a

for i in range(a, 0, -1):
    if a % i == 0 and b % i == 0:
        print(i)
        break

i = 1
while a*i % b != 0:
    i += 1
print(a*i)
