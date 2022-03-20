#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

vector<string> solution(vector<string> arr, vector<string> p) {
    vector<vector<int>> v(p.size(), vector<int>());
    for (int i = 0; i < p.size(); i++) { // r:0 W:1
        int start = 6;
        if (p[i][0] == 'r') {
            v[i].push_back(0);
            start--;
        }
        else {
            v[i].push_back(1);
        }

        int temp = 0;
        for (int j = start; j < p[i].length(); j++) {
            if (p[i][j] == ' ') {
                v[i].push_back(temp);
                temp = 0;
                continue;
            }
            temp = temp * 10 + p[i][j] - 48;
        }
        v[i].push_back(temp);
        v[i].push_back(1);
    }

    vector<int> n(arr.size(), 0);
    for (int i = 0; i < n.size(); i++) {
        n[i] = stoi(arr[i]);
    }

    deque<int> r;
    deque<int> w;

    vector<string> answer;
    int seconds = 0;
    int worktime = 0;
    int count = 0;
    int cur = 0; // r- w+
    while (true) {
        seconds++;
        if (count == v.size()) break;

        worktime++;

        for (int i = 0; i < v.size(); i++) {
            if (v[i][v[i].size() - 1] == 1 && v[i][1] <= seconds) {
                if (v[i][0] == 0) {
                    r.push_back(i);
                }
                else {
                    w.push_back(i);
                }

                v[i][v[i].size() - 1] = 0;
            }
            else if (v[i][1] > seconds) break;
        }

        if (cur == 0) { // 아무것도안하는중
            if (!w.empty()) {
                int temp = w.front();
                for (int i = v[temp][3]; i <= v[temp][4]; i++) {
                    n[i] = v[temp][5];
                }
                w.pop_front();
                cur += v[temp][2] - 1;
                count++;
            }
            else if (!r.empty()) {
                while (!r.empty()) {
                    int temp = r.front();
                    string str = "";
                    for (int i = v[temp][3]; i <= v[temp][4]; i++) {
                        str += to_string(n[i]);
                    }
                    answer.push_back(str);
                    r.pop_front();
                    cur = min(cur, (v[temp][2] - 1) * -1);
                    count++;
                }
            }
            else {
                worktime--;
            }
        }
        else if (cur > 0) { // 쓰는중
            cur--;
        }
        else { // 읽는중
            cur++;
            if (w.empty()) {
                while (!r.empty()) {
                    int temp = r.front();
                    string str = "";
                    for (int i = v[temp][3]; i <= v[temp][4]; i++) {
                        str += to_string(n[i]);
                    }
                    answer.push_back(str);
                    r.pop_front();
                    cur = min(cur, (v[temp][2] - 1) * -1);
                    count++;
                }
            }
        }
    }

    worktime += abs(cur);
    answer.push_back(to_string(worktime));

    return answer;
}