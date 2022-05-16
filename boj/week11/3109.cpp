#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 04 12 21 29
//2022 05 16 17 21


int main() {
    // boj 1806

    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<vector<int>> v(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == 'x') v[i][j] = -1;
        }
    }

    int answer = 0;
    vector<int> p(c, 0);
    for (int i = 0; i < r; i++) {

        deque<pair<int, int>> d;
        d.push_back({ i, 0 });
        while (!d.empty()) {
            int x = d.front().first;
            int y = d.front().second;
            d.pop_front();
            p[y] = x;
            
            if (y == c - 1) {
                answer++;
                for (int j = 0; j < c; j++) {
                    v[p[j]][j] = answer;
                }
                break;
            }

            int flag = 0;
            for (int k = -1; k <= 1; k++) {
                if (x - k >= 0 && x - k < r && v[x - k][y + 1] == 0) {
                    d.push_front({ x - k, y + 1 });
                    flag = 1;
                }
            }
            
            if(flag == 0) {
                v[x][y] = -1;
            }
        }
    }

    
    cout << answer;
    return 0;
}