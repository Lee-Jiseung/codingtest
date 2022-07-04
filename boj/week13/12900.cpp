#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> v(n+1, 0);
    v[0] = 1;
    v[1] = 1;
    
    int index = 2;
    while(v[n] == 0) {
        v[index] = (v[index-1]+ v[index-2]) % 1000000007;
        index++;
    }
    return v[n];
}