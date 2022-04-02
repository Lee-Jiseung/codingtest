#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n; 

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<pair<int, int>>> d(n, vector<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int x, y;
            cin >> x >> y;
            d[i].push_back({ --x,y });
        }
    }

    vector<int> p(n, 0);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    int answer = 10001;
    do {
        int sum = 0;
        vector<int> v2 = { v.begin(), v.end() };

        for (int i = 0; i < n; i++) {
            sum += v2[p[i]];
            for (int j = 0; j < d[p[i]].size(); j++) {
                v2[d[p[i]][j].first] = max(1, v2[d[p[i]][j].first] - d[p[i]][j].second);
            }
        }

        answer = min(answer, sum);
    } while (next_permutation(p.begin(), p.end()));

    cout << answer;

    return 0;
}