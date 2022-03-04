#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 05 00 11
//2022 03 05 00 31

bool comp(pair<string, int> p1, pair<string, int> p2) {
    if (p1.first < p2.first) return true;
    return false;
}

int main() {
    // boj 17219

    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> a(n);
    vector<string> p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> p[i];
        a[i].second = i;
    }

    sort(a.begin(), a.end(), comp);

    vector<pair<string, int>> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end(), comp);

    vector<string> answer(m);
    int x = 0, y = 0;
    int temp = x;
    while (y < m) {
        if (a[x].first == v[y].first) {
            answer[v[y].second] = p[a[x].second];
            y++;
        }
        else {
            x++;
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}