#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 03 23 16 35
//2022 03 23 17 02


int main() {
    // boj 1043
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m + 1, vector<int>(n + 1, 0));

    int t;
    cin >> t;
    vector<int> knowTruth(n + 1, 0);
    deque<int> d;
    for (int i = 0; i < t; i++) {
        int temp;
        cin >> temp;
        d.push_back(temp);
    }

    for (int i = 1; i <= m; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int temp;
            cin >> temp;
            v[i][temp] = 1;
        }
    }

    vector<int> tf(m + 1, 1);
    while (!d.empty()) {
        int index = d.front();
        d.pop_front();
        knowTruth[index] = 1;

        for (int i = 1; i <= m; i++) {
            if (v[i][index] == 1 && tf[i] == 1) {
                tf[i] = 0;
                for (int j = 1; j <= n; j++) {
                    if (v[i][j] == 1 && knowTruth[j] == 0) {
                        d.push_back(j);
                    }
                }
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= m; i++) {
        count += tf[i];
    }
    cout << count;
    
    return 0;
}