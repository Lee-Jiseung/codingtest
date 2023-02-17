import sys

m, s = map(int, sys.stdin.readline().split()) # 물고기 수와 마법의 횟수
fish = [list(map(lambda x: int(x)-1, sys.stdin.readline().split())) for _ in range(m)] # 물고기 정보 [행, 열, 방향]
shark = list(map(lambda x: int(x)-1, sys.stdin.readline().split())) # 상어의 위치 [행, 열]
board = [[0 for _ in range(4)] for _ in range(4)] # 격자
dr8 = [0, -1, -1, -1, 0, 1, 1, 1] # 왼쪽부터 시계방향
dc8 = [-1, -1, 0, 1, 1, 1, 0, -1]
dr4 = [-1, 0, 1, 0] # 상좌하우
dc4 = [0, -1, 0, 1]
fish_count = [[0 for _ in range(4)] for _ in range(4)] # 격자 칸마다 물고기 수
for r, c, _ in fish:
    fish_count[r][c] += 1


for _ in range(s):
    new_fish = [] # 새로운 물고기 정보를 저장할 배열
    for r, c, d in fish:
        if r == -1: # 죽은 물고기는 제외
            continue
        newr = r + dr8[d]  # 물고기의 새로운 위치 (한 칸 이동)
        newc = c + dc8[d]
        newd = d
        while newr < 0 or newr >= 4 or newc < 0 or newc >= 4 or (shark[0] == newr and shark[1] == newc) or board[newr][newc] > 0:
            newd = (newd+7)%8
            newr = r + dr8[newd] # 격자를 벗어나지 않고 상어를 만나지 않고 냄새가 나지 않는 칸을 찾을 때 까지 반복
            newc = c + dc8[newd]
            if newd == d: # 이동할 칸이 없으면 그만, 이동 X
                newr = r
                newc = c
                break
        fish_count[r][c] -= 1 # 물고기 옮기기
        new_fish.append([newr, newc, newd])
        fish_count[newr][newc] += 1

    shark_r = [shark[0]] + [0] * 3 # 상어의 이동 경로를 저장
    shark_c = [shark[1]] + [0] * 3
    max_count = -1 # 상어가 잡아먹는 물고기 수
    max_shark = [] # 상어가 최대로 잡아먹었을 때의 경로
    for i in range(4):
        shark_r[1] = shark_r[0] + dr4[i]
        shark_c[1] = shark_c[0] + dc4[i]
        if shark_r[1] < 0 or shark_r[1] >= 4 or shark_c[1] < 0 or shark_c[1] >= 4:
            continue
        for j in range(4):
            shark_r[2] = shark_r[1] + dr4[j]
            shark_c[2] = shark_c[1] + dc4[j]
            if shark_r[2] < 0 or shark_r[2] >= 4 or shark_c[2] < 0 or shark_c[2] >= 4:
                continue
            for k in range(4):
                shark_r[3] = shark_r[2] + dr4[k]
                shark_c[3] = shark_c[2] + dc4[k]
                if shark_r[3] < 0 or shark_r[3] >= 4 or shark_c[3] < 0 or shark_c[3] >= 4:
                    continue
                count = 0
                visited = [[False for _ in range(4)] for _ in range(4)]
                for l in range(1, 4):
                    if visited[shark_r[l]][shark_c[l]]:
                        continue
                    count += fish_count[shark_r[l]][shark_c[l]]
                    visited[shark_r[l]][shark_c[l]] = True
                if max_count < count:
                    max_count = count
                    max_shark = [shark_r[:], shark_c[:]]

    for i in range(1, 4): # 상어의 이동경로를 따라 물고기 먹고 냄새 남기기
        r = max_shark[0][i]
        c = max_shark[1][i]
        flag = False
        for j, (fishr, fishc, _) in enumerate(new_fish):
            if r == fishr and c == fishc:
                new_fish[j][0] = -1
                fish_count[fishr][fishc] -= 1
                flag = True
        if flag:
            board[r][c] = 3
    shark = [max_shark[0][3], max_shark[1][3]]  # 상어 이동
    for i in range(4):
        for j in range(4):
            if board[i][j] > 0:
                board[i][j] -= 1

    for r, c, d in fish:
        if r==-1:
            continue
        new_fish.append([r, c, d])
        fish_count[r][c] += 1
    fish = new_fish

answer = 0
for r, _, _ in fish:
    if r != -1:
        answer += 1
print(answer)
