#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 2022 02 12 17 42
// 2022 02 12 17 54

int main() {

	int n, s;
	cin >> n >> s;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(abs(temp - s));
	}

	sort(v.begin(), v.end());

	int m = 0;
	while (m==0 || v[0] / m > 1) {
		m++;
		if (v[0] % m != 0) {
			continue;
		}

		int flag = 1;
		for (int i = 1; i < n; i++) {
			if (v[i] % (v[0] / m) != 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) break;
	}

	cout << v[0] / m;
	return 0;
}