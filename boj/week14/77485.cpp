#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> v(rows, vector<int>(columns, 0));
    
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            v[i][j] = i*columns + j +1;
        }
    }
    
    for(int i=0; i<queries.size(); i++) {
        int x1 = queries[i][0]-1;
        int y1 = queries[i][1]-1;
        int x2 = queries[i][2]-1;
        int y2 = queries[i][3]-1;
        
        int lefttop = v[x1][y1];
        int mn = lefttop;
        
        for(int j=x1; j<x2; j++) {
            v[j][y1] = v[j+1][y1];
            mn = min(mn, v[j][y1]);
        }
        for(int j=y1; j<y2;j++) {
            v[x2][j] = v[x2][j+1];
            mn = min(mn, v[x2][j]);
        }
        for(int j=x2; j>x1; j--) {
            v[j][y2] = v[j-1][y2];
            mn = min(mn, v[j][y2]);
        }
        for(int j=y2; j>y1+1;j--) {
            v[x1][j] = v[x1][j-1];
            mn = min(mn, v[x1][j]);
        }
        v[x1][y1+1] = lefttop;
        
        answer.push_back(mn);
    }
    return answer;
}