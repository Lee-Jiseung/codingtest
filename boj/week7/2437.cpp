#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 11 22 52
//2022 03 12 16 09


int main() {
    // boj 2437

    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long temp = 1;
    for (int i = 0; i < n; i++) {
        if (temp >= v[i]) {
            temp += v[i];
        }
        else {
            break;
        }
    }

    cout << temp;
    return 0;
}