#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 04 08 19 57
//2022 04 10 17 21


int main() {
    // boj 4179

    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<vector<int>> v(r, vector<int>(c, 0));
    deque<pair<int, int>> fire;
    string s;
    int x = 0, y = 0;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == '#') v[i][j] = -1;
            else if (s[j] == '.') v[i][j] = 0;
            else if (s[j] == 'J') {
                x = i;
                y = j;
            }
            else if (s[j] == 'F') {
                fire.push_back({ i,j });
                v[i][j] = 1;
            }
        }
    }

    int answer = 1;
    vector<int> dx = { -1, 0,1,0 };
    vector<int> dy = { 0,1,0,-1 };
    deque<pair<int, int>> d;
    d.push_back({ x,y });
    vector<vector<int>> visited(r, vector<int>(c, 0));
    visited[x][y] = 1;

    while (true) {
        answer++;

        int firesize = fire.size();
        while (firesize--) {
            x = fire.front().first;
            y = fire.front().second;
            fire.pop_front();

            for (int k = 0; k < 4; k++) {
                int newi = x + dx[k];
                int newj = y + dy[k];
                if (newi >= 0 && newi < r && newj >= 0 && newj < c && v[newi][newj] == 0) {
                    fire.push_back({ newi, newj });
                    v[newi][newj] = 1;
                }
            }
        }

        int dsize = d.size();
        while (dsize--) {
            x = d.front().first;
            y = d.front().second;
            d.pop_front();

            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (newx < 0 || newx >= r || newy < 0 || newy >= c) {
                    cout << answer -1 ;
                    return 0;
                }
                else if (v[newx][newy] == 0 && visited[newx][newy] == 0) {
                    visited[newx][newy] = 1;
                    d.push_back({ newx, newy });
                }
            }
        }

        if (d.size() == 0) break;
    }


    cout << "IMPOSSIBLE";
    return 0;
}