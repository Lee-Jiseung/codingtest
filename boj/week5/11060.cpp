#include <iostream>
#include <vector>

using namespace std;
//2022 02 21 17 47
//2022 02 21 18 04

int main() {

	int n;
	cin >> n;

	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int cur = n - 1;
	int answer = 0;
	while (cur != 0) {
		int temp = cur;
		for (int i = cur; i >= 0; i--) {
			if (v[i] + i >= cur) {
				temp = i;
			}
		}
		answer++;
		if (temp == cur) {
			cout << -1;
			return 0;
		}
		cur = temp;
	}

	cout << answer;
}