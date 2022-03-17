#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 03 17 17 20
//2022 03 17 17 42

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main() {
    // boj 11000

    int n;
    cin >> n;

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        p.push_back({ s, 1 });
        p.push_back({ t, -1 });
    }
    sort(p.begin(), p.end(), comp);

    int answer = 0;
    int count = 0;
    int prev = -1;
    for (int i = 0; i < p.size(); i++) {
        if (prev != p[i].first) {
            answer = max(answer, count);
        }

        prev = p[i].first;
        count += p[i].second;
    }
    answer = max(answer, count);

    cout << answer;
    return 0;
}