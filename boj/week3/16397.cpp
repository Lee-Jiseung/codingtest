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

int bb(int temp) {
	if (temp >= 50000 || temp == 0) return -1;

	int num = temp * 2;

	int e = 10000;
	while (e > 0) {
		if (num / e == 0) {
			e /= 10;
			continue;
		}

		num -= e;
		break;
	}

	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t, g;
	cin >> n >> t >> g;

	vector<int> v(100000, -1);
	v[n] = 0;
	deque<int> d(1, n);

	while (true) {
		if (d.empty()) {
			cout << "ANG";
			break;
		}

		int temp = d.front();
		d.pop_front();
		
		if (v[temp] > t) {
			cout << "ANG";
			break;
		}
		if (temp == g) {
			cout << v[temp];
			break;
		}

		int a = temp + 1;
		if (a <= 99999 && v[a] == -1) {
			v[a] = v[temp] + 1;
			d.push_back(a);
		}
		int b = bb(temp);
		if (b > 0 && v[b] == -1) {
			v[b] = v[temp] + 1;
			d.push_back(b);
		}
	}

	return 0;
}