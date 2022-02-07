#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <deque>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(NULL));

	vector<char> dslr;
	dslr.push_back('D');
	dslr.push_back('S');
	dslr.push_back('L');
	dslr.push_back('R');

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;

		deque<int> d(1, a);
		vector<string> dp(10001);

		while (true) {
			int temp = d.front();
			d.pop_front();

			if (temp == b) {
				break;
			}

			vector<int> v(4);
			v[0] = (2 * temp) % 10000;
			v[1] = (temp + 9999) % 10000;
			v[2] = (10 * temp + temp / 1000) % 10000;
			v[3] = (temp + (temp % 10) * 10000) / 10;

			for (int j = 0; j < 4; j++) {
				if (dp[v[j]].length() == 0 && v[j] != a) {
					dp[v[j]] = dp[temp] + dslr[j];
					d.push_back(v[j]);
				}
			}

		}

		cout << dp[b] << '\n';
	}

	return 0;
}