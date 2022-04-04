#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 04 04 19 19
//2022 04 04 19 46


int main() {
    // boj 6593

    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, r, c;
    cin >> l >> r >> c;

    while (l + r + c != 0) {
        vector<vector<vector<int>>> v(l, vector<vector<int>>(r, vector<int>(c, 0)));
        string s;
        vector<int> start;
        vector<int> end;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                cin >> s;
                for (int k = 0; k < c; k++) {
                    if (s[k] == 'S') {
                        //v[i][j][k] = 1;
                        start = { i,j,k };
                    }
                    else if (s[k] == 'E') {
                        end = { i,j,k };
                        //v[i][j][k] = 2;
                    }
                    else if (s[k] == '#') {
                        v[i][j][k] = -1;
                    }
                }
            }
        }

        deque<vector<int>> d;
        d.push_back(start);
        int second = 0;
        while (!d.empty()) {
            int ll = d.front()[0];
            int rr = d.front()[1];
            int cc = d.front()[2];
            d.pop_front();

            if (ll == end[0] && rr == end[1] && cc == end[2]) {
                break;
            }

            if (ll > 0 && v[ll - 1][rr][cc] == 0) {
                v[ll - 1][rr][cc] = v[ll][rr][cc] + 1;
                d.push_back({ ll - 1, rr,cc });
            }
            if (ll < l - 1 && v[ll + 1][rr][cc] == 0) {
                v[ll + 1][rr][cc] = v[ll][rr][cc] + 1;
                d.push_back({ ll + 1, rr,cc });
            }
            if (rr > 0 && v[ll][rr - 1][cc] == 0) {
                v[ll][rr - 1][cc] = v[ll][rr][cc] + 1;
                d.push_back({ ll, rr - 1,cc });
            }
            if (rr < r - 1 && v[ll][rr + 1][cc] == 0) {
                v[ll][rr + 1][cc] = v[ll][rr][cc] + 1;
                d.push_back({ ll, rr + 1,cc });
            }
            if (cc > 0 && v[ll][rr][cc - 1] == 0) {
                v[ll][rr][cc - 1] = v[ll][rr][cc] + 1;
                d.push_back({ ll, rr, cc - 1 });
            }
            if (cc < c - 1 && v[ll][rr][cc + 1] == 0) {
                v[ll][rr][cc + 1] = v[ll][rr][cc] + 1;
                d.push_back({ ll, rr,cc + 1 });
            }
        }

        if (v[end[0]][end[1]][end[2]] == 0) {
            cout << "Trapped!\n";
        }
        else {
            cout << "Escaped in " << v[end[0]][end[1]][end[2]] << " minute(s).\n";
        }
        
        cin >> l >> r >> c;
    }
    return 0;
}