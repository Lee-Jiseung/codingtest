#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 05 15 23
//2022 03 05 18 42

int main() {
    // boj 17143

    int r, c, m;
    cin >> r >> c >> m;

    vector<vector<int>> v(r + 1, vector<int>(c + 1, 0));
    vector<vector<int>> s(m + 1, vector<int>(6, 1)); // 행, 열, 속력, 방향, 크기, 생존여부
    for (int i = 1; i <= m; i++) {
        cin >> s[i][0] >> s[i][1] >> s[i][2] >> s[i][3] >> s[i][4];
        v[s[i][0]][s[i][1]] = i;
    }

    vector<int> dr = { -1, 1, 0, 0 };
    vector<int> dc = { 0, 0, 1, -1 };

    int answer = 0;
    for (int i = 1; i <= c; i++) {

        for (int j = 1; j <= r; j++) {
            if (v[j][i] > 0) {
                answer += s[v[j][i]][4];
                s[v[j][i]][5] = 0;
                v[j][i] = 0;

                break;
            }
        }

        for (int j = 1; j <= m; j++) {
            if (s[j][5] == 0) continue;

            v[s[j][0]][s[j][1]] = 0;

            s[j][0] += dr[s[j][3] - 1] * s[j][2];
            s[j][1] += dc[s[j][3] - 1] * s[j][2];
            while (s[j][0] < 1 || s[j][0] > r) {
                if (s[j][3] == 1) s[j][3] = 2;
                else s[j][3] = 1;

                if (s[j][0] < 1) s[j][0] = s[j][0] * (-1) + 2;
                else s[j][0] = r - (s[j][0] - r);
            }
            while (s[j][1] < 1 || s[j][1] > c) {
                if (s[j][3] == 3) s[j][3] = 4;
                else s[j][3] = 3;
            
                if (s[j][1] < 1) s[j][1] = s[j][1] * (-1) + 2;
                else s[j][1] = c - (s[j][1] - c);
            }
        }

        for (int j = 1; j <= m; j++) {
            if (s[j][5] == 0) continue;

            if (v[s[j][0]][s[j][1]] == 0) v[s[j][0]][s[j][1]] = j;
            else if (s[j][4] > s[v[s[j][0]][s[j][1]]][4]) {
                s[v[s[j][0]][s[j][1]]][5] = 0;
                v[s[j][0]][s[j][1]] = j;
            }
            else {
                s[j][5] = 0;
            }
        }
    }

    cout << answer;

    return 0;
}