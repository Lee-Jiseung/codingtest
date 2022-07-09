#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int n = s.length();
    int answer = n;
    
    for(int i=1; i<=n/2; i++) {
        
        string tempAnswer = "";
        string str = s.substr(0, i);
        int count=1;
        for(int j=1; (n%i) ? j<=n/i : j<n/i; j++) {
            string temp = s.substr(j*i,i);
            
            if(temp == str) count++;
            else {
                if(count > 1) tempAnswer += to_string(count);
                tempAnswer += str;
                str = temp;
                count=1;
            }
        }
        if(count > 1) tempAnswer += to_string(count);
        tempAnswer += str;
        
        answer = min(answer, (int) tempAnswer.length());
    }
    return answer;
}