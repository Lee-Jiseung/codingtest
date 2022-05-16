#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 04 08 19 02
//2022 05 05 13 33

int main() {
    // boj 3343

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    if (b * c > d * a) {
        long long temp = a;
        a = c;
        c = temp;

        temp = b;
        b = d;
        d = temp;
    }

    long long first = n / a + 1;
    if (n % a == 0) first--;

    vector<int> v(max(a, c) + 1, 0);
    long long answer = 1e18;
    for (long long i = first; i >= 0LL; i--) {
        long long remainder = max(0LL, n - i * a);
    
        long long second = remainder / c + 1;
        if (remainder % c == 0) second = max(0LL, second - 1);

        if (v[(i * a + second * c) % n] == 1) break;
        v[(i * a + second * c) % n] = 1;
        
        answer = min(answer, i * b + second * d);
    }

    cout << answer;

   
    return 0;
}