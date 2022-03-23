#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 23 16 30
//2022 03 23 16 33


int main() {
    // boj 17608
    
    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int h = v[n - 1];
    int count = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] > h) {
            h = v[i];
            count++;
        }
    }
    
    cout << count;

    return 0;
}