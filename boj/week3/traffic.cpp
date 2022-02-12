#include <string>
#include <vector>

using namespace std;


int solution(vector<string> lines) {
    
    vector<int> table(24*60*60*1000, 0);
    
    vector<pair<int, int>> v;
    for (int i = 0; i < lines.size(); i++) {
        vector<int> end(4, 0);
        end[0] = (lines[i][11] - 48) * 10 + lines[i][12] - 48;
        end[1] = (lines[i][14] - 48) * 10 + lines[i][15] - 48;
        end[2] = (lines[i][17] - 48) * 10 + lines[i][18] - 48;
        end[3] = (lines[i][20] - 48) * 100 + (lines[i][21] - 48) * 10 + lines[i][22] - 48;
        int endtime = end[3] + end[2] * 1000 + end[1] * 1000 * 60 + end[0] * 1000* 60 *60;

        int duration = -1;
        int e = 1000;
        for(int j=24; j<lines[i].length()-1;j++) {
            if(j == 25) continue;
            duration += (lines[i][j] - 48) * e;
            e /= 10;
        }
        
        int starttime = endtime-duration -999;
        if(starttime <0) starttime = 0;
        
        for(int j=starttime; j<=endtime; j++) {
            table[j]++;
        }
        
    }

    int answer = 0;
    for(int i=0;i<table.size();i++) {
        answer = max(table[i], answer);
    }
    return answer;
}