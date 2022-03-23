#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 03 20 19 09
//2022 03 23 17 44


int main() {
    // boj 2206
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            v[i][j] = s[j] - 48;
        }
    }

    vector<int> dx = { -1, 0, 1, 0 };
    vector<int> dy = { 0, 1, 0 ,-1 };
    
    vector<vector<pair<int, int>>> v2(n, vector<pair<int, int>>(m, { n * m + 1, n * m + 1 }));
    deque<vector<int>> d;
    d.push_back({ 0,0,0,1 }); // x y flag count
    while (!d.empty()) {
        vector<int> temp = { d.front().begin(), d.front().end() };
        d.pop_front();
        
        if (temp[2] == 0) {
            if (temp[3] >= v2[temp[0]][temp[1]].first) continue;
            v2[temp[0]][temp[1]].first = temp[3];
        }
        else {
            if (temp[3] >= v2[temp[0]][temp[1]].second) continue;
            v2[temp[0]][temp[1]].second = temp[3];
        }

        for (int i = 0; i < 4; i++) {
            int newx = temp[0] + dx[i];
            int newy = temp[1] + dy[i];
            if (newx < 0 || newx >= n || newy < 0 || newy >= m) continue;

            if (v[newx][newy] == 1 && temp[2] == 0) {
                d.push_back({ newx, newy, 1, temp[3] + 1 });
            }
            else if (v[newx][newy] == 0) {
                d.push_back({ newx, newy, temp[2], temp[3] + 1 });
            }
        }
    }

    if (min(v2[n - 1][m - 1].first, v2[n - 1][m - 1].second) == n * m + 1) cout << -1;
    else cout << min(v2[n - 1][m - 1].first, v2[n - 1][m - 1].second);
    
    return 0;
}