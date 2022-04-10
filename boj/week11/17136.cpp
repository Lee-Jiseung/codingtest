#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 04 10 13 59
//2022 04 10 14 22

vector<vector<int>> v;
vector<int> used(6, 0);
int answer = 26;

void attach(int r, int c) {
    if (r == 10) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (v[i][j] == 1) {
                    return;
                }
            }
        }

        int count = 0;
        for (int i = 1; i <= 5; i++) count += used[i];
        answer = min(answer, count);
        return;
    }
    if (c == 10) {
        attach(r + 1, 0);
        return;
    }
    if (v[r][c] == 0) {
        attach(r, c + 1);
        return;
    }

    for (int l = 1; l <= 5; l++) {
        if (used[l] >= 5) continue;

        int flag = 1;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                int newr = r + i;
                int newc = c + j;
                if (newr < 0 || newr >= 10 || newc < 0 || newc >= 10 || v[newr][newc] == 0) {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag == 1) {
            vector<pair<int, int>> rc;
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < l; j++) {
                    if (v[r + i][c + j] == 1) {
                        rc.push_back({ r + i, c + j });
                        v[r + i][c + j] = 0;
                    }
                }
            }
            used[l]++;
            attach(r, c + 1);
            for (int i = 0; i < rc.size(); i++) {
                v[rc[i].first][rc[i].second] = 1;
            }
            used[l]--;
        }
    } 
}

int main() {
    // boj 17136

    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>>(10, vector<int>(10, 0)).swap(v);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> v[i][j];
        }
    }

    attach(0, 0);

    if (answer == 26) cout << -1;
    else cout << answer;
    return 0;
}