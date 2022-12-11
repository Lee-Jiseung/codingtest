import sys

r = 31
m = 1234567891
l = int(sys.stdin.readline())
str = input()

H = 0
ri = 1
for c in str:
    airi = (ord(c)-96) * ri % m
    H = (H + airi) % m
    ri = ri * r % m
print(H)
