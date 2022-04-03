#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 04 03 21 56
//2022 04 03 22 16


int main() {
    // boj 21938

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> color(n, vector<int>(m * 3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m * 3; j++) {
            cin >> color[i][j];
        }
    }

    int t;
    cin >> t;

    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m * 3; j+=3) {
            if (color[i][j] + color[i][j + 1] + color[i][j + 2] >= t * 3) {
                v[i][j / 3] = -1;
            }
        }
    }

    int count = 0;
    deque<pair<int, int>> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == -1) {
                v[i][j] = ++count;
                d.push_back({ i,j });

                while (!d.empty()) {
                    int x = d.front().first;
                    int y = d.front().second;
                    d.pop_front();

                    if (x > 0 && v[x-1][y] == -1) {
                        v[x-1][y] = count;
                        d.push_back({ x - 1,y });
                    }
                    if (x < n - 1 && v[x+1][y] == -1) {
                        v[x+1][y] = count;
                        d.push_back({ x + 1,y });
                    }
                    if (y > 0 &&  v[x][y-1] == -1) {
                        v[x][y-1] = count;
                        d.push_back({ x,y-1 });
                    }
                    if (y < m - 1 && v[x][y+ 1] == -1) {
                        v[x][y+1] = count;
                        d.push_back({ x,y + 1});
                    }
                }
            }
        }
    }

    cout << count;

    return 0;
}