#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 03 05 01 33
//2022 03 05 14 30

int n;
int condition = 1;
vector<int> v;
vector<int> answer;

int isItGood(int count) {
    if (count == 1) return v[v.size() - 1];

    int flag = 1;
    for (int i = 1; i < count; i++) {
        if (v[v.size() - i - count] != v[v.size() - i]) {
            flag = 0;
            break;
        }
    }

    if (flag == 1) {
        return v[v.size() - count];
    }

    return 0;
}

void recur() {
    if (condition == 0) return;
    if (v.size() == n) {
        condition = 0;
        answer = { v.begin(), v.end() };
        return;
    }
    if (v.size() == 0) {
        for (int i = 1; i <= 3; i++) {
            v.push_back(i);
            recur();
            v.pop_back();
        }
        return;
    }

    vector<int> temp(4, 1);
    for (int i = 1; i <= (v.size() + 1) / 2; i++) {
        temp[isItGood(i)] = 0;
    }

    for (int i = 1; i < 4; i++) {
        if (temp[i] == 1 && condition == 1) {
            v.push_back(i);
            recur();
            v.pop_back();
        }
    }

}

int main() {
    // boj 2661

    cin >> n;

    recur();

    for (int i = 0; i < n; i++) cout << answer[i];

    return 0;
}