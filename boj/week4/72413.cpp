#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> f;
vector<int> v;
vector<pair<vector<int>, int>> p;
vector<int> info(5);

void sToa(int cur, int count, int fare) {
    if (v[info[2]] != 0) {
        p.push_back({ v, fare });
        return;
    }

    for (int i = 1; i <= info[0]; i++) {
        if (v[i] == 0 && f[cur][i] > 0 && i != info[3]) {
            v[i] = count + 1;
            sToa(i, count + 1, fare + f[cur][i]);
            v[i] = 0;
        }
    }
}

void aTob(int cur, int count, int fare) {
    if (fare > info[4]) return;

    if (v[info[3]] < 0) {
        info[4] = min(info[4], fare);
        return;
    }

    for (int i = 1; i <= info[0]; i++) {
        if (v[i] == 0 && f[cur][i] > 0) {
            v[i] = count - 1;
            aTob(i, count - 1, fare + f[cur][i]);
            v[i] = 0;
        }
    }

}

void sTob(int cur, int count, int fare) {
    if (fare > info[4]) return;

    if (v[info[3]] != 0) {
        p.push_back({ v, fare });
        return;
    }

    for (int i = 1; i <= info[0]; i++) {
        if (v[i] == 0 && f[cur][i] > 0 && i != info[2]) {
            v[i] = count + 1;
            sTob(i, count + 1, fare + f[cur][i]);
            v[i] = 0;
        }
    }
}

void bToa(int cur, int count, int fare) {
    if (fare > info[4]) return;

    if (v[info[2]] < 0) {
        info[4] = min(info[4], fare);
        return;
    }

    for (int i = 1; i <= info[0]; i++) {
        if (v[i] == 0 && f[cur][i] > 0) {
            v[i] = count - 1;
            bToa(i, count - 1, fare + f[cur][i]);
            v[i] = 0;
        }
    }

}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    info[0] = n;
    info[1] = s;
    info[2] = a;
    info[3] = b;
    info[4] = 20000000;
    vector<vector<int>>(n + 1, vector<int>(n + 1, 0)).swap(f);
    for (int i = 0; i < fares.size(); i++) {
        f[fares[i][0]][fares[i][1]] = fares[i][2];
        f[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    int answer = 0;
    vector<int>(n + 1, 0).swap(v);
    v[s] = 1;
    sToa(s, 1, 0);

    for (int i = 0; i < p.size(); i++) {
        int ans = p[i].second;
        for (int j = 1; j <= n; j++) {
            if (p[i].first[j] > 0) {
                v = { p[i].first.begin(), p[i].first.end() };
                v[j] = -1;
                aTob(j, -1, p[i].second);
            }
        }
    }
    
    vector<pair<vector<int>, int>>().swap(p);
    vector<int>(n + 1, 0).swap(v);
    v[s] = 1;
    sTob(s, 1, 0);

    for (int i = 0; i < p.size(); i++) {
        int ans = p[i].second;
        for (int j = 1; j <= n; j++) {
            if (p[i].first[j] > 0) {
                v = { p[i].first.begin(), p[i].first.end() };
                v[j] = -1;
                bToa(j, -1, p[i].second);
            }
        }
    }
    return info[4];
}