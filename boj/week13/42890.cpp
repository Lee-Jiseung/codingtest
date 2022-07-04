#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int n = relation.size();
    int m = relation[0].size();
    
    vector<vector<string>> r(m, vector<string>(n, ""));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = relation[j][i];
        }
    }

    m = n;
    n = r.size();
    vector<string> candidateKeys;
    for (int i = 1; i <= n; i++) {
        vector<int> p(n, 0);
        for (int j = 0; j < i; j++) p[n-1-j] = 1;

        do {
            string str = "";
            for (int j = 0; j < p.size(); j++) {
                if (p[j] == 1) str += j + 48;
            }
            
            for (int j = 0; j < candidateKeys.size(); j++) {
                int count = 0;
                int i1 =0, i2=0;
                while(i1<str.length() && i2<candidateKeys[j].length()) {
                    if(str[i1] == candidateKeys[j][i2]) {
                        count++;
                        i1++; i2++;
                    }else if(str[i1] > candidateKeys[j][i2]) {
                        i2++;
                    }else {
                        i1++;
                    }
                }
                
                if(count == candidateKeys[j].length()) {
                    str= "";
                    break;
                }
            }
            if (str == "") continue;

            vector<string> temp(m, "");
            for (int j = 0; j < p.size(); j++) {
                if (p[j] == 1) {
                    for (int k = 0; k < temp.size(); k++) {
                        temp[k] += r[j][k];
                    }
                }
            }
            sort(temp.begin(), temp.end());
            temp.erase(unique(temp.begin(), temp.end()), temp.end());

            if (temp.size() == m) {
                candidateKeys.push_back(str);
            }
        } while (next_permutation(p.begin(), p.end()));
    }

    answer = candidateKeys.size();
    return answer;
}