#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 03 23 19 23
//2022 03 24 20 54


int main() {
    // boj 15971
    
    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<int>> input(n - 1, vector<int>(3, 0));
    for (int i = 0; i < n - 1; i++) {
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }

    vector<vector<pair<int, int>>> v(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; i++) {
        v[input[i][0]].push_back({ input[i][1],input[i][2] });
        v[input[i][1]].push_back({ input[i][0],input[i][2] });
    }
    
    vector<int> aton(n + 1, 0);
    vector<int> visited(n + 1, 0);
    deque<int> d;
    d.push_back(a);
    while (!d.empty()) {
        int cur = d.front();
        d.pop_front();
        
        for (int i = 0; i < v[cur].size(); i++) {
            if (visited[v[cur][i].first] == 1) continue;
            aton[v[cur][i].first] = aton[cur] + v[cur][i].second;
            d.push_back(v[cur][i].first);
        }
        visited[cur] = 1;
    }

    vector<int> bton(n + 1, 0);
    vector<int>(n + 1, 0).swap(visited);
    d.push_back(b);
    while (!d.empty()) {
        int cur = d.front();
        d.pop_front();

        for (int i = 0; i < v[cur].size(); i++) {
            if (visited[v[cur][i].first] == 1) continue;
            bton[v[cur][i].first] = bton[cur] + v[cur][i].second;
            d.push_back(v[cur][i].first);
        }
        visited[cur] = 1;
    }

    int answer = 1000000001;
    for (int i = 0; i < n - 1; i++) {
        answer = min(answer, min(aton[input[i][0]] + bton[input[i][1]], aton[input[i][1]] + bton[input[i][0]]));
    }
    for (int i = 1; i <= n; i++) {
        answer = min(answer, aton[i] + bton[i]);
    }
    cout << answer;
    
    return 0;
}