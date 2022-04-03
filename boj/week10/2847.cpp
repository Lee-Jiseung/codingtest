#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 04 03 21 52
//2022 04 03 21 56


int main() {
    // boj 2847

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    
    int answer = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] >= v[i + 1]) {
            answer += v[i] - v[i + 1] + 1;
            v[i] = v[i + 1] - 1;
        }
    }
    
    cout << answer;
    return 0;
}