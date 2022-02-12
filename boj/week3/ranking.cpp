#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    
    vector<pair<int, int>> v(info.size(), {0,0});

    for (int i = 0; i < info.size(); i++) {
        int flag = 1;
        int count = 0;
        string temp = "";
        
        for (int j = 0; j < info[i].length(); j++) {
            if (flag == 1) {
                if (count == 0) {
                    if (info[i][j] == 'c') {
                        v[i].first += (1<<8);
                    }
                    else if (info[i][j] == 'j') {
                        v[i].first += (1<<7);
                    }
                    else if (info[i][j] == 'p') {
                        v[i].first += (1<<6);
                    }
                    flag = 0;
                }
                else if (count == 1) {
                    if (info[i][j] == 'b') {
                        v[i].first += (1<<5);
                    }
                    else if (info[i][j] == 'f') {
                        v[i].first += (1<<4);
                    }
                    flag = 0;
                }
                else if (count == 2) {
                    if (info[i][j] == 'j') {
                        v[i].first += (1<<3);
                    }
                    else if (info[i][j] == 's') {
                        v[i].first += (1<<2);
                    }
                    flag = 0;
                }
                else if (count == 3) {
                    if (info[i][j] == 'c') {
                        v[i].first += (1<<1);
                    }
                    else if (info[i][j] == 'p') {
                        v[i].first += (1<<0);
                    }
                    flag = 0;
                }
                else if (count == 4) {
                    temp += info[i][j];
                }
            }
            else if (flag == 0) {
                if (info[i][j] == ' ') {
                    flag = 1;
                    count++;
                }
            }
        }
        v[i].second = stoi(temp);
    }
    
    vector<pair<int, int>> v2(query.size(), {0, 0});
    for (int i = 0; i < query.size(); i++) {
        int flag = 1;
        int count = 0;
        string temp = "";

        for (int j = 0; j < query[i].length(); j++) {
            if (flag == 1) {
                if (count == 0) {
                    if (query[i][j] == 'c') {
                        v2[i].first += (1<<8);
                    }
                    else if (query[i][j] == 'j') {
                        v2[i].first += (1<<7);
                    }
                    else if (query[i][j] == 'p') {
                        v2[i].first += (1<<6);
                    }
                    flag = 0;
                }
                else if (count == 2) {
                    if (query[i][j] == 'b') {
                        v2[i].first += (1<<5);
                    }
                    else if (query[i][j] == 'f') {
                        v2[i].first += (1<<4);
                    }
                    flag = 0;
                }
                else if (count == 4) {
                    if (query[i][j] == 'j') {
                        v2[i].first += (1<<3);
                    }
                    else if (query[i][j] == 's') {
                        v2[i].first += (1<<2);
                    }
                    flag = 0;
                }
                else if (count == 6) {
                    if (query[i][j] == 'c') {
                        v2[i].first += (1<<1);
                    }
                    else if (query[i][j] == 'p') {
                        v2[i].first += (1<<0);
                    }
                    flag = 0;
                }
                else if (count == 7) {
                    temp += query[i][j];
                }
                else flag = 0;
            }
            else if (flag == 0) {
                if (query[i][j] == ' ') {
                    flag = 1;
                    count++;
                }
            }
        }

        if (temp == "-") v2[i].second =-1;
        else v2[i].second = stoi(temp);
    }
    
    
    vector<int> answer;
    for(int i=0;i<query.size();i++) {
        answer.push_back(0);
        for(int k=0; k<info.size();k++) {
            int flag = 1;
            for(int j=0;j<9;j++) {
                if(v2[i].first & (1<<j)) {
                    if(!(v[k].first & (1<<j))) {
                        flag = 0;
                        break;
                    }
                }
            }

            if(flag == 1 && v[k].second >= v2[i].second) {
                answer[i]++;
            }
        }
    }
    return answer;
}