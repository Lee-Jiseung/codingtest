#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<int>> v(m, vector<int>(n, 0));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            v[i][j] = board[i][j];
        }
    }
    
    vector<int> dr = {0,0,1,1};
    vector<int> dc = {0,1,0,1};
    while(true) {
        vector<pair<int, int>> v2;
        
        for(int i=0; i<m-1;i++) {
            for(int j=0;j<n-1;j++) {
                if(v[i][j] == 0) continue;
                
                int flag = 1;
                for(int k=1;k<4 && flag;k++) {
                    if(v[i][j] != v[i+dr[k]][j+dc[k]]) {
                        flag = 0;
                    }
                }
                
                if(flag) v2.push_back({i,j});
            }
        }
        
        if(v2.size() == 0) break;
        
        for(int i=0; i<v2.size(); i++) {
            for(int j=0;j<4;j++) {
                v[v2[i].first + dr[j]][v2[i].second + dc[j]] = 0;
            }
        }
        
        vector<vector<int>> temp(m, vector<int>(n,0));
        for(int i=0; i<n;i++) {
            int r = m-1;
            for(int j=m-1;j>=0;j--) {
                if(v[j][i] >0) {
                    temp[r][i] = v[j][i];
                    r--;
                }
            }
        }
        temp.swap(v);
    }
    
    for(int i=0; i<m;i++) {
        for(int j=0;j<n;j++) {
            answer += (v[i][j] >0);
        }
    }
    return m*n -answer;
}