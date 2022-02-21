#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> f;
vector<int> v;
vector<pair<vector<int>, int>> p;
vector<int> nsab(5);

void sToFirst(int cur, int count, int fare) {
    if (v[nsab[2]] != 0 || v[nsab[3]] != 0) {
        p.push_back({ v, fare });
        return;
    }

    for (int i = 1; i <= nsab[0]; i++) {
        if (v[i] == 0 && f[cur][i] > 0) {
            v[i] = count + 1;
            sToFirst(i, count + 1, fare + f[cur][i]);
            v[i] = 0;
        }
    }
}

void firstToSecond(int cur, int count, int fare) {
    if (fare > nsab[4]) return;

    if (v[nsab[3]] != 0 && v[nsab[2]] != 0) {
        nsab[4] = min(nsab[4], fare);
        return;
    }

    for (int i = 1; i <= nsab[0]; i++) {
        if (v[i] == 0 && f[cur][i] > 0) {
            v[i] = count - 1;
            firstToSecond(i, count - 1, fare + f[cur][i]);
            v[i] = 0;
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    nsab[0] = n;
    nsab[1] = s;
    nsab[2] = a;
    nsab[3] = b;
    nsab[4] = 20000000;
    vector<vector<int>>(n + 1, vector<int>(n + 1, 0)).swap(f);
    for (int i = 0; i < fares.size(); i++) {
        f[fares[i][0]][fares[i][1]] = fares[i][2];
        f[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    int answer = 0;
    vector<int>(n + 1, 0).swap(v);
    v[s] = 1;
    sToFirst(s, 1, 0);

    for (int i = 0; i < p.size(); i++) {
        for (int j = 1; j <= n; j++) {
            if (p[i].first[j] > 0) {
                v = { p[i].first.begin(), p[i].first.end() };
                v[j] = -1;
                firstToSecond(j, -1, p[i].second);
            }
        }
    }

    return nsab[4];
}
