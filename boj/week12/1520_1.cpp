#include <iostream>
#include <vector>

using namespace std;
//

int m, n;
vector<vector<int>> v;
vector<vector<int>> dp;
vector<int> dr = { -1, 1 , 0, 0 };
vector<int> dc = { 0, 0, -1, 1 };

int dfs(int x, int y) {
    if (x == m && y == n) return 1;
    int temp = dp[x][y];
    if (temp != -1) return temp;
    temp = 0;

    for (int i = 0; i < 4; i++) {
        int newx = x + dr[i];
        int newy = y + dc[i];
        if (v[x][y] > v[newx][newy]) {
            temp += dfs(newx, newy);
        }
    }
    dp[x][y] = temp;
    return temp;
}

int main() {
    // boj 1520

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;
    vector<vector<int>>(m+2, vector<int>(n+2, 10001)).swap(v);
    vector<vector<int>>(m+2, vector<int>(n+2, -1)).swap(dp);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    cout << dfs(1, 1);

    return 0;
}