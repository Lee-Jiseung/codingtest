#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
//2022 03 11 22 45
//2022 03 11 22 49


int main() {
    // boj 2161

    int n;
    cin >> n;

    deque<int> d;
    for (int i = 0; i < n; i++) {
        d.push_back(i + 1);
    }

    cout << d.front() << ' ';
    d.pop_front();
    while (!d.empty()) {
        d.push_back(d.front());
        d.pop_front();

        cout << d.front() << ' ';
        d.pop_front();
    }

    return 0;
}