#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 05 02 16 40
//2022 05 02 16 51

int main() {
    // boj 3029

    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    vector<int> v = { 36000,3600,0,600,60,0,10,1 };
    int t1 = 0, t2 = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (i % 3 == 2) continue;

        t1 += (s1[i] - 48) * v[i];
        t2 += (s2[i] - 48) * v[i];
    }

    if (t1 >= t2) {
        t2 += 24 * 3600;
    }
    
    int answer = t2 - t1;
    for (int i = 0; i < s1.length(); i++) {
        if (i % 3 == 2) {
            cout << ':';
            continue;
        }

        cout << answer / v[i];
        answer -= (answer / v[i]) * v[i];
    }

    return 0;
}