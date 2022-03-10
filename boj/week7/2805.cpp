#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 07 17 21
//2022 03 10 15 49


int main() {
    // boj 2805

    long long n, m;
    cin >> n >> m;

    vector<long long> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    v.push_back(0);

    sort(v.begin(), v.end());

    int answer = 0;
    for (int i = n - 1; i >= 0; i--) {
        m -= (v[i + 1] - v[i]) * (n - i);
        
        if (m <= 0) {
            answer = v[i] + m * (-1) / (n - i);
            break;
        }
    }

    cout << answer;

    return 0;
}