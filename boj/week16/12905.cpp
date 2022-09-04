#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int r = board.size();
    int c = board[0].size();
    
    vector<vector<int>> dp(r, vector<int>(c, 0));
    for(int i=0; i<r; i++) {
        int last1 = -1;
        for(int j=c-1; j>=0; j--) {
            if(board[i][j] == 1) {
                if(last1 < 0) {
                    last1 = j;
                }
                dp[i][j] = last1-j+1;
            }else {
                last1 = -1;
            } 
        }
    }
    for(int i=0; i<c; i++) {
        int last1 = -1;
        for(int j=r-1; j>=0; j--) {
            if(board[j][i] == 1) {
                if(last1 < 0) {
                    last1 = j;
                }
                dp[j][i] = min(dp[j][i], last1-j+1);
            }else {
                last1 = -1;
            } 
        }
    }
    
    vector<vector<int>> visited(r, vector<int>(c, 0));
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(visited[i][j] == 1) continue;
            if(dp[i][j] <= answer) continue;
            
            int k=0;
            int mn = dp[i][j];
            for(; k<mn; k++) {
                visited[i+k][j+k] = 1;
                if(dp[i+k][j+k] == 0) break;
                if(dp[i+k][j+k] < mn - k) {
                    mn = min(mn, dp[i+k][j+k]+k);
                }
            }
            answer = max(answer, k);
        }
    }
    
    return answer*answer;
}