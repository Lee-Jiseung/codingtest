#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 17 16 55
//2022 03 17 17 04

int main() {
    // boj 16194

    int n;
    cin >> n;

    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<int> dp(n + 1, 100000001);
    dp[0] = 0;
    dp[1] = v[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = min(dp[i - j] + v[j], dp[i]);
        }
    }

    cout << dp[n];
    return 0;
}