#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    vector<int> v(8, 0); //RT CF JM AN
    string types = "RTCFJMAN";
    vector<int> choiceToScore1 = {3, 2, 1};
    vector<int> choiceToScore2 = {1, 2, 3};
    
    for(int i=0; i<survey.size(); i++) {
        if(choices[i] == 4) continue;
        
        int type = 0;
        if(choices[i]>4) type=1;
        
        int index;
        for(index = 0; index<8; index++) {
            if(types[index] == survey[i][type]) {
                break;
            }
        }
        
        if(type == 1) {
            v[index] += choiceToScore2[choices[i]-5];
        }else {
            v[index] += choiceToScore1[choices[i]-1];
        }
    }
    
    for(int i=0; i<8; i+=2) {
        if(v[i] < v[i+1]) {
            answer += types[i+1];
        }else {
            answer += types[i];
        }
    }
    return answer;
}