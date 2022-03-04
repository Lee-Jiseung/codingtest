#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 04 23 56
//2022 03 05 00 01

int main() {
    // boj 1439

    string s;
    cin >> s;

    int count0 = 0, count1 = 0;
    char prev = s[0];
    if (prev == '0') count0++;
    else count1++;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] != prev) {
            if (prev == '0') {
                count1++;
            }
            else {
                count0++;
            }
        }
        prev = s[i];
    }

    cout << min(count0, count1) << '\n';
    return 0;
}