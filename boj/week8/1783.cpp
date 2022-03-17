#include <iostream>
#include <algorithm>

using namespace std;
//2022 03 17 17 45
//2022 03 17 18 31

int n, m;

int move(int x, int y, int count) {
    if (count == 5) return 4;
    if (x < 0 || y < 0 || x >= n || y >= m) return count - 1;

    int answer = count;
    answer = max(answer ,move(x - 2, y + 1, count + 1));
    answer = max(answer, move(x - 1, y + 2, count + 1));
    answer = max(answer, move(x + 1, y + 2, count + 1));
    answer = max(answer, move(x + 2, y + 1, count + 1));

    return answer;
}

int main() {
    // boj 1783

    cin >> n >> m;

    if (n > 2 && m > 6) {
        cout << m - 2;
        return 0;
    }

    cout << move(n - 1, 0, 1);
    return 0;
}