#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> numbers = {'4', '1', '2', '4'};
    vector<int> v = {3,1,2};
    
    while (n > 0) {
        int d = n % 3;
        answer += numbers[d];
        n -= v[d];
        n /= 3;
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}