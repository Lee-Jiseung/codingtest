#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 04 03 21 25
//2022 04 03 21 33


int main() {
    // boj 2720

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int c;
        cin >> c;
        vector<int> coin = { 25, 10, 5, 1 };

        vector<int> v(c + 1, 501);
        v[0] = 0;
        vector<vector<int>> num(c + 1, vector<int>(4, 0));
        for (int i = 1; i <= c; i++) {
            for (int j = 0; j < coin.size(); j++) {
                if (i - coin[j] >= 0) {
                    if (v[i] > v[i - coin[j]] + 1) {
                        v[i] = v[i - coin[j]] + 1;
                        num[i] = { num[i - coin[j]].begin(), num[i - coin[j]].end() };
                        num[i][j]++;
                    }
                }
            }
        }

        for (int i = 0; i < coin.size(); i++) {
            cout << num[c][i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}