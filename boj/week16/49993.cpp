#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<int> priorities(26, -1);
    for(int i=0; i<skill.length(); i++) {
        priorities[skill[i]-'A'] = i;
    }
    
    for(int i=0; i<skill_trees.size(); i++) {
        int flag = 0;
        for(int j=0; j<skill_trees[i].length(); j++) {
            if(priorities[skill_trees[i][j]-'A'] == flag) {
                flag++;
            }else if(priorities[skill_trees[i][j]-'A'] > 0) {
                flag = -1;
                break;
            } 
        }
        
        if(flag != -1) answer++;
    }
    
    return answer;
}