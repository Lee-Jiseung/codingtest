import sys
from collections import defaultdict

def func1(index, num):
    global s, left, lefts, answer

    if index == len(left):
        return
    if num + left[index] == s:
        answer += 1

    lefts.append(num + left[index])
    lefts_count[num+left[index]] += 1
    func1(index+1, num + left[index])
    func1(index+1, num)


def func2(index, num):
    global s, right, rights, answer

    if index == len(right):
        return
    if num + right[index] == s:
        answer += 1

    rights.append(num + right[index])
    rights_count[num+right[index]] += 1
    func2(index+1, num)
    func2(index+1, num + right[index])


n, s = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
left = nums[:n//2]
right = nums[n//2:]
answer = 0
lefts = []
lefts_count = defaultdict(int)
rights = []
rights_count = defaultdict(int)
func1(0, 0)
func2(0, 0)
lefts = sorted(list(set(lefts)))
rights = sorted(list(set(rights)))
for l in lefts:
    start = 0
    end = len(rights)
    while start < end:
        mid = (start+end)//2
        if l + rights[mid] == s:
            answer += lefts_count[l]*rights_count[rights[mid]]
            break
        if l + rights[mid] < s:
            start = mid + 1
        else:
            end = mid
print(answer)
