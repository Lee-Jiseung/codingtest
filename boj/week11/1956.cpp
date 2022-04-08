#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 04 08 19 22
//2022 04 08 19 42


int main() {
    // boj 1956

    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;

    vector<vector<pair<int, int>>> edges(v+1, vector<pair<int, int>>());
    for (int i = 0; i < e; i++) {
        int x, y, d;
        cin >> x >> y >> d;

        edges[x].push_back({ y,d });
    }

    int answer = 1600000000;
    for (int i = 1; i <= v; i++) {
        deque<pair<int, int>> d;
        d.push_back({ i, 0 });

        vector<int> visited(v + 1, -1);
        visited[i] = 0;
        while (!d.empty()) {
            int cur = d.front().first;
            int dist = d.front().second;
            d.pop_front();            
            
            for (int j = 0; j < edges[cur].size(); j++) {
                int next = edges[cur][j].first;
                if (next == i) {
                    answer = min(answer, dist + edges[cur][j].second);
                }
                else if (visited[next] == -1 || visited[next] > dist + edges[cur][j].second) {
                    visited[next] = edges[cur][j].second;
                    d.push_back({ next, dist + edges[cur][j].second });
                }
            }
        }
    }

    if (answer == 1600000000) cout << -1;
    else cout << answer;

    return 0;
}