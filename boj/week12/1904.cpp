#include <iostream>

using namespace std;
//2022 05 02 18 56
//2022 05 02 19 07

int main() {
    // boj 1904

    ios::sync_with_stdio(false);
    cin.tie(0);

    int divisor = 15746;
    int n;
    cin >> n;

    int prev = 1;
    int cur = 2;
    if (n == 1) {
        cout << prev;
        return 0;
    }else if(n==2) {
        cout << cur;
        return 0;
    }
    
    for (int i = 3; i <= n; i++) {
        int temp = cur;
        cur += prev;
        cur %= divisor;
        prev = temp;
    }

    cout << cur;
    return 0;
}