#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {

    vector<vector<int>> v(3 * 2 * 2 * 2, vector<int>(100001, 0));
    for (int i = 0; i < info.size(); i++) {
        int flag = 1;
        int count = 0;
        string temp = "";
        int index = 0;

        for (int j = 0; j < info[i].length(); j++) {
            if (flag == 1) {
                if (count == 0) {
                    if (info[i][j] == 'j') {
                        index += 8;
                    }
                    else if (info[i][j] == 'p') {
                        index += 16;
                    }
                    flag = 0;
                }
                else if (count == 1) {
                    if (info[i][j] == 'f') {
                        index += 4;
                    }
                    flag = 0;
                }
                else if (count == 2) {
                    if (info[i][j] == 's') {
                        index += 2;
                    }
                    flag = 0;
                }
                else if (count == 3) {
                    if (info[i][j] == 'p') {
                        index += 1;
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
        v[index][stoi(temp)]++;
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = v[i].size() - 2; j >= 0; j--) {
            v[i][j] += v[i][j + 1];
        }
    }

    vector<int> answer;
    for (int i = 0; i < query.size(); i++) {
        int flag = 1;
        int count = 0;
        string temp = "";
        deque<int> d;

        for (int j = 0; j < query[i].length(); j++) {
            if (flag == 1) {
                if (count == 0) {
                    if (query[i][j] == 'c') {
                        d.push_back(0);
                    }
                    else if (query[i][j] == 'j') {
                        d.push_back(8);
                    }
                    else if (query[i][j] == 'p') {
                        d.push_back(16);
                    }
                    else {
                        d.push_back(0);
                        d.push_back(8);
                        d.push_back(16);
                    }
                    flag = 0;
                }
                else if (count == 2) {
                    int ds = d.size();
                    if (query[i][j] == 'b') {
                        for (int k = 0; k < ds; k++) {
                            d.push_back(d.front() + 0);
                            d.pop_front();
                        }
                    }
                    else if (query[i][j] == 'f') {
                        for (int k = 0; k < ds; k++) {
                            d.push_back(d.front() + 4);
                            d.pop_front();
                        }
                    }
                    else {
                        for (int k = 0; k < ds; k++) {
                            d.push_back(d.front() + 0);
                            d.push_back(d.front() + 4);
                            d.pop_front();
                        }
                    }
                    flag = 0;
                }
                else if (count == 4) {
                    int ds = d.size();
                    if (query[i][j] == 'j') {
                        for (int k = 0; k < ds; k++) {
                            d.push_back(d.front() + 0);
                            d.pop_front();
                        }
                    }
                    else if (query[i][j] == 's') {
                        for (int k = 0; k < ds; k++) {
                            d.push_back(d.front() + 2);
                            d.pop_front();
                        }
                    }
                    else {
                        for (int k = 0; k < ds; k++) {
                            d.push_back(d.front() + 0);
                            d.push_back(d.front() + 2);
                            d.pop_front();
                        }
                    }
                    flag = 0;
                }
                else if (count == 6) {
                    int ds = d.size();
                    if (query[i][j] == 'c') {
                        for (int k = 0; k < ds; k++) {
                            d.push_back(d.front() + 0);
                            d.pop_front();
                        }
                    }
                    else if (query[i][j] == 'p') {
                        for (int k = 0; k < ds; k++) {
                            d.push_back(d.front() + 1);
                            d.pop_front();
                        }
                    }
                    else {
                        for (int k = 0; k < ds; k++) {
                            d.push_back(d.front() + 0);
                            d.push_back(d.front() + 1);
                            d.pop_front();
                        }
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

        int score = 0;
        if (temp == "-") score = 0;
        else score = stoi(temp);

        answer.push_back(0);
        while (!d.empty()) {
            answer[i] += v[d.front()][score];
            d.pop_front();
        }
    }

    return answer;
}