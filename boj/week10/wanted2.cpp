#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> doorNum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> doorNum[i];
    }

    vector<vector<int>> edges(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        vector<int> visited(n + 1, 0);
        deque<pair<int, int>> d;
        d.push_back({ x, doorNum[x] });

        while (!d.empty()) {
            int cur = d.front().first;
            visited[cur] = 1;
            int num = d.front().second;
            d.pop_front();

            if (cur == y) {
                cout << num << '\n';
                break;
            }

            for (int j = 0; j < edges[cur].size(); j++) {
                if (visited[edges[cur][j]] == 0) {
                    d.push_back({ edges[cur][j], stoull(to_string(num) + to_string(doorNum[edges[cur][j]])) % 1000000007 });
                }
            }
        }
    }

    return 0;
}