#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 04 08 19 44
//2022 04 08 19 55

vector<vector<int>> v;
void backTracking(int r, int c) {
    if (c == 9) {
        backTracking(r + 1, 0);
        return;
    }
    if (r == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << v[i][j];
            }
            cout << '\n';
        }
        exit(0);
    }
    if (v[r][c] != 0) {
        backTracking(r, c + 1);
        return;
    }
    
    for (int i = 1; i <= 9; i++) {
        int flag = 1;
        for (int j = 0; j < 9; j++) {
            if (v[r][j] == i || v[j][c] == i) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            for (int j = (r / 3) * 3; j < (r / 3) * 3 + 3; j++) {
                for (int k = (c / 3) * 3; k < (c / 3) * 3 + 3; k++) {
                    if (v[j][k] == i) {
                        flag = 0;
                        break;
                    }
                }
            }
        }

        if (flag == 1) {
            v[r][c] = i;
            backTracking(r, c + 1);
            v[r][c] = 0;
        }
    }
}

int main() {
    // boj 2239

    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>>(9, vector<int>(9, 0)).swap(v);
    string s;
    for (int i = 0; i < 9; i++) {
        cin >> s;
        for (int j = 0; j < 9; j++) {
            v[i][j] = s[j] - 48;
        }
    }

    backTracking(0, 0);
    return 0;
}