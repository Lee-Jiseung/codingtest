#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    
    vector<int> v(26, 0);
    for(int i=1; i<26;i++) {
        v[i] =i;
    }
    for(int i=25;i>=0;i--) {
        if(i > 26 - i) {
            v[i] = 26-i;
        }else break;
    }
    
    for(int i=0;i<n;i++) {
        answer += v[name[i] - 65];
    }

    
    vector<int> notA;
    for(int i=0;i<n; i++) {
        if(name[i]!='A') notA.push_back(i);
    }
    
    if(notA.size()==0) return answer;
    
    int temp = min(notA[notA.size() -1], n-notA[0]);
    for(int i=0;i<notA.size()-1;i++) {
        temp = min(temp, min(2*notA[i]+n-notA[i+1], 2*(n-notA[i+1])+notA[i]));
    }
    
    answer += temp;
    
    return answer;
}