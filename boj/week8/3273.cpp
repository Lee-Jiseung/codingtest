#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 03 17 16 36
//2022 03 1

int main() {
    // boj 3273

    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int x;
    cin >> x;

    int l = 0;
    int r = n - 1;
    int answer = 0;
    int flag = -1;
    while (l < r) {
        if (v[l] + v[r] > x) {
            if (flag == 1) {
                l++;
            }
            else if (flag == -1) {
                r--;
            }
        }
        else if (v[l] + v[r] ==  x) {
            answer++;
            l++;
        }
        else {
            if (flag == 1) {
                r++;
                flag = 1;
            }
            else if (flag == -1) {
                l++;
            }
        }
    }

    cout << answer;
    return 0;
}