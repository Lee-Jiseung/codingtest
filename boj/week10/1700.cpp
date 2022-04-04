#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 04 04 19 47
//2022 04 04 20 31


int main() {
    // boj 1700

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(k, 0);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        v[i]--;
    }
    
    int answer = 0;
    int curUsing = 0;
    vector<int> cur(k, 0);
    for (int i = 0; i < k; i++) {
        if (cur[v[i]] == 1) continue;

        if (curUsing < n) {
            cur[v[i]] = 1;
            curUsing++;
            continue;
        }

        int largest = 0;
        int index = 0;
        for (int j = 0; j < k; j++) {
            if (cur[j] == 0) continue;

            int temp = 0;
            for (int l = i + 1; l < k; l++) {
                if (v[l] == j) {
                    temp = l - i;
                    break;
                }
            }
            if (temp == 0) {
                index = j;
                break;
            }
            if (temp > largest) {
                largest = temp;
                index = j;
            }
        }
        answer++;
        cur[index] = 0;
        cur[v[i]] = 1;
    }

    cout << answer;
    return 0;
}