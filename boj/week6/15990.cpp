#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 05 00 33
//2022 03 05 01 01

int main() {
    // boj 15990

    int t;
    cin >> t;

    int large = 3;
    vector<int> v(t, 0);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
        large = max(large, v[i]);
    }

    vector<vector<long long>> dp(large + 1, vector<long long>(4, 0));
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for (int i = 4; i < dp.size(); i++) {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
    }

    for (int i = 0; i < v.size(); i++) {
        cout << (dp[v[i]][1]+ dp[v[i]][2]+ dp[v[i]][3]) % 1000000009 << '\n';
    }

    return 0;
}