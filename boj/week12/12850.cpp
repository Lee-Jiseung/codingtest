#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
//2022 05 02 18 32
//2022 05 24 18 17

int main() {
    // boj 12850

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long dividor = 1'000'000'007;
    long long d;
    cin >> d;

    vector<vector<long long>> v(8, vector<long long>(8, 0)); // 0정 1전 2신 3진 4학 5형 6한 7미
    v[0][1] = 1, v[0][7] = 1;
    v[1][0] = 1, v[1][2] = 1, v[1][7] = 1;
    v[2][1] = 1, v[2][3] = 1, v[2][6] = 1, v[2][7] = 1;
    v[3][2] = 1, v[3][4] = 1, v[3][6] = 1;
    v[4][3] = 1, v[4][5] = 1;
    v[5][4] = 1, v[5][6] = 1;
    v[6][2] = 1, v[6][3] = 1, v[6][5] = 1, v[6][7] = 1;
    v[7][0] = 1, v[7][1] = 1, v[7][2] = 1, v[7][6] = 1;
    
    vector<vector<vector<long long>>> dp;
    dp.push_back(v);
    for (int ii = 0; ii < 30; ii++) {
        vector<vector<long long>> newv(8, vector<long long>(8, 0));
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                long long sum = 0LL;
                for (int k = 0; k < 8; k++) {
                    sum += dp[ii][i][k] * dp[ii][k][j];
                    sum %= dividor;
                }
                newv[i][j] = sum;
            }
        }
        dp.push_back(newv);
    }

    vector<int> count;
    for (int i = 29; i >= 0;i--) {
        int temp = pow(2, i);
        if (d >= temp) {
            d -= temp;
            count.push_back(i);
        }
    }
    
    vector<vector<long long>> answer = { dp[count.front()].begin(), dp[count.front()].end() };
    for (int ii = 1; ii < count.size(); ii++) {
        vector<vector<long long>> newv(8, vector<long long>(8, 0));
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                long long sum = 0LL;
                for (int k = 0; k < 8; k++) {
                    sum += answer[i][k] * dp[count[ii]][k][j];
                    sum %= dividor;
                }
                newv[i][j] = sum;
            }
        }
        newv.swap(answer);
    }

    cout << answer[0][0];
    return 0;
}