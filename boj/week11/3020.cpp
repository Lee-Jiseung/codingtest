#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 04 08 18 37
//2022 04 08 19 01


int main() {
    // boj 3020

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, h;
    cin >> n >> h;

    vector<int> bottomUp(h+1, 0);
    vector<int> topDown(h + 1, 0);
    for (int i = 0; i < n; i+=2) {
        int temp;
        cin >> temp;
        bottomUp[temp - 1]++;
        cin >> temp;
        topDown[h - temp]++;
    }

    for (int i = h - 1; i >= 0; i--) {
        bottomUp[i] += bottomUp[i + 1];
    }
    for (int i = 1; i < h + 1; i++) {
        topDown[i] += topDown[i - 1];
    }

    int answer = n + 1, num = 0;
    for (int i = 0; i < h; i++) {
        int count = bottomUp[i] + topDown[i];
        
        if (answer > count) {
            answer = count;
            num = 1;
        }
        else if (answer == count) {
            num++;
        }
    }

    cout << answer << ' ' << num;
    return 0;
}