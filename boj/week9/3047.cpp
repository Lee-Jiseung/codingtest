#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 23 16 24
//2022 03 23 16 29


int main() {
    // boj 3047
    
    vector<pair<int, int>> v(3, { 0,0 });
    for (int i = 0; i < 3; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    string s;
    cin >> s;
    for (int i = 0; i < 3; i++) {
        cout << v[s[i] - 65].first << ' ';
    }

    return 0;
}