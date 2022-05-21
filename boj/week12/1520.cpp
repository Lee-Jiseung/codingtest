#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 04 21 21 22
//2022 05 21 16 42

int main() {
    // boj 1520

    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    vector<int> dr = { -1, 0 , 1, 0 };
    vector<int> dc = { 0, 1, 0, -1 };

    vector<vector<vector<int>>> g(m, vector<vector<int>>(n, vector<int>(4, 0)));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int newi = i + dr[k];
                int newj = j + dc[k];
                if (newi >= 0 && newi < m && newj >= 0 && newj < n) {
                    if (v[i][j] > v[newi][newj]) {
                        g[i][j][k] = 1;
                    }
                    else if (v[i][j] < v[newi][newj]) {
                        g[i][j][k] = -1;
                    }
                }
            }
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));
    vector<pair<int, int>> path;
    dp[m - 1][n - 1] = 1;
    deque<vector<int>> d;
    d.push_front({ 0,0,1 });

    while (!d.empty()) {
        int r = d.front()[0];
        int c = d.front()[1];
        int distance = d.front()[2];
        d.pop_front();

        while (path.size() >= distance) path.pop_back();
        path.push_back({ r,c });

        if (dp[r][c] != 0) {
            for (int i = path.size() - 2; i >= 0; i--) {
                int child = 0, grownChild = 0, deadChild = 0, temp = 0;
                for (int k = 0; k < 4; k++) {
                    if (g[path[i].first][path[i].second][k] == 1) {
                        child++;
                        int target = dp[path[i].first + dr[k]][path[i].second + dc[k]];
                        if (target > 0) {
                            temp += target;
                            grownChild++;
                        }
                        else if (target < 0) {
                            deadChild++;
                        }
                    }
                }

                if (child == grownChild + deadChild && child > 0) {
                    if (temp > 0) dp[path[i].first][path[i].second] = temp;
                    else dp[path[i].first][path[i].second] = -1;
                }
                if (child == 0) dp[path[i].first][path[i].second] = -1;
            }
        }
        else {
            int flag = 0;
            for (int k = 0; k < 4; k++) {
                if (g[r][c][k] == 1) {
                    if (dp[r + dr[k]][c + dc[k]] >= 0) {
                        d.push_front({ r + dr[k], c + dc[k], distance + 1 });
                        flag = 1;
                    }
                }
            }

            if (flag == 0) {
                for (int i = path.size() - 1; i >= 0; i--) {
                    int child = 0, grownChild = 0, deadChild = 0, temp = 0;
                    for (int k = 0; k < 4; k++) {
                        if (g[path[i].first][path[i].second][k] == 1) {
                            child++;
                            int target = dp[path[i].first + dr[k]][path[i].second + dc[k]];
                            if (target > 0) {
                                temp += target;
                                grownChild++;
                            }
                            else if (target < 0) {
                                deadChild++;
                            }
                        }
                    }

                    if (child == grownChild + deadChild && child > 0) {
                        if (temp > 0) dp[path[i].first][path[i].second] = temp;
                        else dp[path[i].first][path[i].second] = -1;
                    }
                    if(child == 0) dp[path[i].first][path[i].second] = -1;
                }
            }
        }

    }

    cout << max(0, dp[0][0]);
    return 0;
}