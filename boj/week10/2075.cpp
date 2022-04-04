#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 04 04 14 31
//2022 04 04 14 37


int main() {
    // boj 2075

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    vector<int> index(n, n - 1);
    int large = 0;
    for (int i = 1; i <= n; i++) {
        large = -1000000001;
        int col = 0;

        for (int j = 0; j < n; j++) {
            if (v[index[j]][j] > large) {
                large = v[index[j]][j];
                col = j;
            }
        }

        index[col]--;
    }

    cout << large;
    return 0;
}