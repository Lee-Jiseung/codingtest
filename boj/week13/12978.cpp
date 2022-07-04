#include <vector>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<int>> v(N, vector<int>(N, 500001));
    for(int i=0; i<N; i++) v[i][i] = 0;
    for(int i=0; i<road.size(); i++) {
        v[road[i][0] -1][road[i][1] -1] = min(road[i][2], v[road[i][0] -1][road[i][1] -1]);
        v[road[i][1] -1][road[i][0] -1] = min(road[i][2], v[road[i][1] -1][road[i][0] -1]);
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N;j++) {
            for(int k=0; k<N; k++) {
                v[j][k] = min(v[j][k], v[j][i]+v[i][k]);
            }
        }
    }

    for(int i=0; i<N; i++) {
        if(v[0][i] <= K) answer++;
    }
    
    return answer;
}