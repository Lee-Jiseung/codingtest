#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
//2022 04 03 21 34
//2022 04 03 21 51


int main() {
    // boj 12981

    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v(3, 0);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int answer = v[0];  // 다 다른 색을 하나씩 넣은 주머니를 세 가지 색 중 가장 적게 있는 공의 수만큼 만듦
    v[1] -= v[0];       // 0, v[1]-v[0], v[2]-v[0]
    v[2] -= v[0];

    answer += v[1] / 3; // 같은 색을 3개씩 넣어 최대한 주머니를 많이 만듦
    answer += v[2] / 3; // 0, (v[1]-v[0])%3, (v[2]-v[0])%3
    v[1] %= 3;
    v[2] %= 3;

    if (v[1] == v[2]) { // 0, 0, 0 혹은 0,1,1 혹은 0,2,2 => v[1]개의 주머니
        answer += v[1];
    }
    else if (v[1] * v[2] == 2) { // 0,1,2 혹은 0,2,1 => 주머니 2개
        answer += 2;
    }
    else { // 0,0,1 혹은 0,0,2 혹은 0,1,0 혹은 0,2,0 => 주머니 1개
        answer += 1;
    }

    cout << answer;
    return 0;
}