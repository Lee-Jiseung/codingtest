#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 07 16 28
//2022 03 12 15 55


int main() {
    // boj 1654

    int k, n;
    cin >> k >> n;

    vector<int> v(k, 0);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }

    long long left = 1;
    long long right = 2147483647;
    int answer = 0;
    while (left <= right) {
        long long temp = (left + right) / 2;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += v[i] / temp;
        }

        if (sum >= n) {
            left = temp+1;
            answer = max(answer, (int) temp);
        }
        else if (sum < n) {
            right = temp-1;
        }
    }

    cout << answer;
    return 0;
}