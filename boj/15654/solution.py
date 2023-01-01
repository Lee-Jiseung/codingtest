import sys
from itertools import permutations

n, m = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
nums = sorted(nums)

answer = permutations(nums, m)
for iter in answer:
    print(*iter, sep=' ')
