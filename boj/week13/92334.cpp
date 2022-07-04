#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    vector<vector<int>> v(id_list.size(), vector<int>(id_list.size(), 0));
    
    for(int i=0;i<report.size(); i++) { // 200000
        string s1 = "";
        string s2 = "";
        
        int flag = 0;
        for(int j=0; j<report[i].length(); j++) { // 21
            if(flag == 0) {
                if(report[i][j] == ' ') {
                    flag = 1;
                }else {
                    s1.push_back(report[i][j]);
                }
            }else {
                s2.push_back(report[i][j]);
            }
        }
        
        int x = 0;
        for(int j=0;j<id_list.size(); j++) { // 1000
            if(id_list[j] == s1) {
                x = j;
            }
        }
        
        int y=0;
        for(int j=0; j<id_list.size(); j++) { // 1000
            if(id_list[j] == s2) {
                y=j;
            }
        }
        
        v[y][x] = 1;
    } // 200000*21*1000*1000 = 4.2*e^12
    
    vector<int> answer(id_list.size(), 0);
    for(int i=0; i<id_list.size(); i++) { // 1000
        int sum = 0;
        for(int j=0; j<id_list.size(); j++) { // 1000
            sum += v[i][j];
        }
        
        if(sum >= k) {
            for(int j=0;j<id_list.size(); j++) { // 1000
                if(v[i][j] > 0) answer[j]++;
            }
        }
    } // 1000*1000*1000 = 1.0*e^9
    
    
    return answer;
}