#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 05 14 31
//2022 03 05 15 08

vector<vector<int>> v(3, vector<int>(3, 0));

bool compa(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) return (p1.first < p2.first);
    return (p1.second < p2.second);
}

void operationR() {
    vector<vector<int>> n;
    int large = 0;
    for (int i = 0; i < v.size(); i++) {
        vector<int> count(10000, 0);
        for (int j = 0; j < v[i].size(); j++) {
            count[v[i][j]]++;
        }
        vector<pair<int, int>> p;
        for (int j = 1; j < count.size(); j++) {
            if (count[j] > 0) {
                p.push_back({ j, count[j] });
            }
        }
        sort(p.begin(), p.end(), compa);
        n.push_back(vector<int>());
        for (int j = 0; j < min((int)p.size(), 50); j++) {
            n[i].push_back(p[j].first);
            n[i].push_back(p[j].second);
        }
        large = max(large, (int)n[i].size());
    }

    for (int i = 0; i < n.size(); i++) {
        while (n[i].size() < large) {
            n[i].push_back(0);
        }
    }

    v = { n.begin(), n.end() };
}

void operationC() {
    vector<vector<int>> n;
    int large = 0;
    for (int i = 0; i < v[0].size(); i++) {
        vector<int> count(10000, 0);
        for (int j = 0; j < v.size(); j++) {
            count[v[j][i]]++;
        }
        vector<pair<int, int>> p;
        for (int j = 1; j < count.size(); j++) {
            if (count[j] > 0) {
                p.push_back({ j, count[j] });
            }
        }
        sort(p.begin(), p.end(), compa);
        n.push_back(vector<int>());
        for (int j = 0; j < min((int)p.size(), 50); j++) {
            n[i].push_back(p[j].first);
            n[i].push_back(p[j].second);
        }
        large = max(large, (int)n[i].size());
    }

    for (int i = 0; i < n.size(); i++) {
        while (n[i].size() < large) {
            n[i].push_back(0);
        }
    }

    vector<vector<int>>(n[0].size(), vector<int>(n.size(), 0)).swap(v);
    for (int i = 0; i < n.size(); i++) {
        for (int j = 0; j < n[0].size(); j++) {
            v[j][i] = n[i][j];
        }
    }
}

int main() {
    // boj 17140

    int r, c, k;
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }

    int answer = 0;
    while (v.size() < r || v[0].size() < c || v[r - 1][c - 1] != k) {
        answer++;
        if (answer > 100) {
            answer = -1;
            break;
        }

        if (v.size() >= v[0].size()) operationR();
        else operationC();
    }

    cout << answer;
    return 0;
}