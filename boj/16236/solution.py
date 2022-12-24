import sys


def solution():
    n = int(sys.stdin.readline())
    space = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    cur = []
    for i in range(n):
        for j in range(n):
            if space[i][j] == 9:
                cur = [i, j]
                space[i][j] = 0
                break

    dr = [-1, 0, 1, 0]
    dc = [0, -1, 0, 1]
    seconds = 0
    size = 2
    eat_count = 0
    while True:
        candidates = []
        distances = [[-1 for _ in range(n)] for _ in range(n)]
        distance = 0
        distances[cur[0]][cur[1]] = distance

        while True:
            flag = True
            for i in range(n):
                for j in range(n):
                    if distances[i][j] != distance:
                        continue

                    for dri, dci in zip(dr, dc):
                        newi = i+dri
                        newj = j+dci
                        if newi<0 or newi>=n or newj<0 or newj>=n or space[newi][newj]>size or distances[newi][newj]!=-1:
                            continue

                        flag = False
                        distances[newi][newj] = distance+1
                        if 0 < space[newi][newj] < size:
                            candidates.append([newi, newj])

            if candidates:
                candidates = sorted(candidates, key=lambda x: (x[0], x[1]))
                seconds += distance+1
                cur = candidates[0]
                space[cur[0]][cur[1]] = 0

                eat_count += 1
                if size == eat_count:
                    size += 1
                    eat_count = 0
                print(cur, seconds, size, eat_count)
                break
            if flag:
                return seconds

            distance += 1


print(solution())
