#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
//2022 04 04 18 25
//2022 04 04 19 17


int main() {
    // boj 5355

    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed;
    cout.precision(2);

    string s;
    getline(cin, s);
    int t = stoi(s);

    vector<double> answer;
    while (t--) {
        
        getline(cin, s);

        double d = 0.0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                d = stod(s.substr(0, i));
                
                for (int j = i; j < s.length(); j++) {
                    if (s[j] == ' ') continue;

                    if (s[j] == '@') d *= 3;
                    else if (s[j] == '%') d += 5;
                    else if (s[j] == '#') d -= 7;
                }

                break;
            }
        }

        answer.push_back(d);
    }
    
    for (int i = 0; i < answer.size(); i++) cout << answer[i] << '\n';
    return 0;
}