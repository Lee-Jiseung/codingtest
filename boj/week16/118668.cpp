#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    
    int req_alp = 0;
    int req_cop = 0;
    
    for(int i=0; i<problems.size(); i++) {
        req_alp = max(req_alp, problems[i][0]);
        req_cop = max(req_cop, problems[i][1]);
    }
    alp = min(alp, req_alp);
    cop = min(cop, req_cop);
    
    vector<vector<int>> dp(req_alp+1, vector<int>(req_cop+1, req_alp - alp + req_cop - cop));
    dp[alp][cop] = 0;
    
    deque<vector<int>> d;
    d.push_back({alp, cop, 0});
    
    while(!d.empty()) {
        int a = d.front()[0];
        int c = d.front()[1];
        int time = d.front()[2];
        d.pop_front();
        
        if(time>dp[req_alp][req_cop]) continue;
        if(dp[a][c] < time) continue;
        if(a >= req_alp && c >= req_cop) {
            continue;
        }
        
        if(a<req_alp && dp[a+1][c] > time + 1) {
            dp[a+1][c] = time+1;
            d.push_back({a+1, c, time+1});
        }
        if(c<req_cop && dp[a][c+1] > time + 1) {
            dp[a][c+1] = time+1;
            d.push_back({a, c+1, time+1});
        }
        
        for(int i=0; i<problems.size(); i++) {
            if(a >= problems[i][0] && c >= problems[i][1]) {     
                if((a>=req_alp && problems[i][3] == 0) || (c>=req_cop && problems[i][2] == 0)) continue;
                
                int newa = min(req_alp, a+problems[i][2]);
                int newc = min(req_cop, c+problems[i][3]);
                
                if(dp[newa][newc] > time+problems[i][4]) {
                    dp[newa][newc] = time + problems[i][4];
                    d.push_back({newa, newc, time + problems[i][4]});
                }
            }
        }
    }
    
    return dp[req_alp][req_cop];
}