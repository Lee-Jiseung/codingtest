#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    int countW = 0;
    int countE = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'W') {
            countW++;
            v.push_back(0);
        }
        else if (c == 'H') {
            v.push_back(countW * -1);
        }
        else if (c == 'E') {
            countE++;
            v.push_back(2);
        }
    }

    vector<int> dp(v.size(), 0);
    dp[1] = 2;
    for (int i = 2; i < dp.size(); i++) {
        dp[i] = (dp[i - 1] * 2) % 1000000007;
    }
    
    long long answer = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < 0 && countE >= 2) {
            cout << v[i] << ' ' << countE<<'\n';
            int temp = (dp[countE] + 1000000007 - countE - 1) % 1000000007;#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    int countW = 0;
    int countE = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'W') {
            countW++;
        }
        else if (c == 'H') {
            v.push_back(countW);
        }
        else if (c == 'E') {
            countE++;
            v.push_back(0);
        }
    }

    vector<int> dp(v.size(), 0);
    dp[1] = 2;
    for (int i = 2; i < dp.size(); i++) {
        dp[i] = (dp[i - 1] * 2) % 1000000007;
    }
    
    long long answer = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0 && countE >= 2) {
            cout << v[i] << ' ' << countE<<'\n';
            int temp = (dp[countE] + 1000000007 - countE - 1) % 1000000007;
            answer = (answer + (long long) v[i] * -1 * temp) % 1000000007;
        }
        else if (v[i] == 2) {
            countE--;
        }

    }

    cout << answer;
    return 0;
}
            answer = (answer + (long long) v[i] * -1 * temp) % 1000000007;
        }
        else if (v[i] == 2) {
            countE--;
        }

    }

    cout << answer;
    return 0;
}