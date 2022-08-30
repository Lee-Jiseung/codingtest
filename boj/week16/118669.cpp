#include <string>
#include <vector>
#include <queue>

using namespace std;


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    int minIntensity = 10000001;
    int summit = n + 1;
    int inf = 10000001;

    vector<int> gates2(n + 1, 0);
    vector<int> summits2(n + 1, 0);
    vector<vector<pair<int, int>>> v(n+1, vector<pair<int, int>>());
    
    for (int i = 0; i < gates.size(); i++) {
        gates2[gates[i]] = 1;
    }
    for (int i = 0; i < summits.size(); i++) {
        summits2[summits[i]] = 1;
    }

    for(int i=0; i<paths.size(); i++) {
        if (summits2[paths[i][0]] != 1 && gates2[paths[i][1]] != 1)
            v[paths[i][0]].push_back({paths[i][1], paths[i][2]});
        if (summits2[paths[i][1]] != 1 && gates2[paths[i][0]] != 1)
            v[paths[i][1]].push_back({paths[i][0], paths[i][2]});
    }

    for (int i = 0; i < gates.size(); i++) {
        vector<int> d(n+1, inf);
        d[gates[i]] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, gates[i]);

        while(!pq.empty()) {
            int cur = pq.top().second;
            int temp = pq.top().first;
            pq.pop();
            
            if(temp > minIntensity) continue;
            if(summits2[cur] == 1) {
                if (temp < minIntensity) {
                    minIntensity = temp;
                    summit = cur;
                }
                else if (temp == minIntensity) {
                    summit = min(summit, cur);
                }
                continue;
            }
            
            for(int j=0; j<v[cur].size(); j++) {
                if(d[v[cur][j].first] > max(d[cur], v[cur][j].second)) {
                    d[v[cur][j].first] = max(d[cur], v[cur][j].second);
                    pq.emplace(d[v[cur][j].first], v[cur][j].first);
                }
            }
        }
    }

    return { summit, minIntensity };
}