#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 12 16 10
//2022 03 13 15 05


int main() {
    // boj 17135

    int n, m, d;
    cin >> n >> m >> d;

    vector<vector<int>> enemy; // 적의 행과 열을 저장하는 벡터

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                enemy.push_back({ i, j ,1}); // 행, 열, 생존여부
            }
        }
    }

    vector<int> archers(m, 0); // 궁수들을 위치를 저장하는 벡터
    for (int i = 0; i < 3; i++) {
        archers[i] = 1;
    }
    sort(archers.begin(), archers.end());

    int answer = -1;
    do {
        vector<vector<int>> v = { enemy.begin(), enemy.end() }; // 적의 정보를 저장하는 벡터 복사

        int killed = 0; // 궁수가 죽인 적의 수
        int disappeared = 0; // 보드판을 벗어난 적의 수
        while (killed + disappeared != enemy.size()) { // 죽이거나 벗어난 적의 수가 전체 적의 수가 될 때 까지 반복
            vector<int> c; // 이번 턴에 죽는 적의 인덱스 번호를 저장하는 벡터
            for (int i = 0; i < m; i++) { // 궁수 한명씩 반복
                if (archers[i] == 0) continue; // 궁수가 없으면 continue

                int index = -1; // 죽일 적의 인덱스
                int shortestDistance = n + m + 2; // 죽일 적과의 거리
                int mostLeft = m + 1; // 죽일 적의 열 번호 
                for (int j = 0; j < v.size(); j++) { // 모든 적에 대하여
                    if (v[j][2] == 0) continue; // 이미 죽은 적이면 continue

                    int dist = n - v[j][0] + abs(i - v[j][1]); // 적과 궁수의 거리 
                    if (dist > d) continue; // 거리가 d보다 크면 continue

                    if (shortestDistance > dist) { // 가장 가까운 적이면
                        shortestDistance = dist; // 가장 가까운 거리 갱신
                        index = j; // 죽일 적의 인덱스 번호 갱신
                        mostLeft = v[j][1]; // 죽일 적의 열 번호 갱신
                    }
                    else if (shortestDistance == dist && mostLeft > v[j][1]) { // 여태껏 가장 가까운 적과 거리는 같지만 더 왼쪽에 있는 적일 경우
                        index = j; // 죽일 적의 인덱스 번호 갱신
                        mostLeft = v[j][1]; // 죽일 적의 열 번호 갱신
                    }
                }

                if(index != -1) c.push_back(index); // 이번 궁수가 죽일 적의 인덱스 번호를 추가
            }

            for (int i = 0; i < c.size(); i++) { // 각 궁수가 죽이는 적들에 대하여
                if (v[c[i]][2] == 1) { // 살아있는 적이면
                    v[c[i]][2] = 0; // 생존여부를 0으로 바꿈
                    killed++; // 궁수가 적인 적의 수 + 1
                }
            }

            for (int i = 0; i < v.size(); i++) { // 각 적에 대하여
                if (v[i][2] == 0) continue; // 이미 죽었으면 continue

                v[i][0] += 1; // 한 칸 아래로 이동
                if (v[i][0] == n) { // 보드판을 벗어나는 경우
                    v[i][2] = 0; // 생존여부를 0으로 바꿈
                    disappeared++; // 벗어난 적의 수 + 1
                }
            }
        }

        answer = max(answer, killed); // 여태 최대 죽인 수와 비교
    } while (next_permutation(archers.begin(), archers.end())); // 궁수들을 배치하는 조합을 만드는 반복문
    
    cout << answer;
    return 0;
}