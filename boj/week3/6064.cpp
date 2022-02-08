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

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int k = 1;
		while (true) {
			if ((m * k) % n == 0) break;
			k++;
		}

		int num = x;
		while (true) {
			if (num > m * k) {
				num = -1;
				break;
			}

			if ((num % n == 0 && y == n) || (num % n == y)) {
				break;
			}
			num += m;
		}
		
		cout << num << '\n';
	}
	return 0;
}