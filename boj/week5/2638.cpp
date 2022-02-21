#include <iostream>
#include <vector>
#include <string>

using namespace std;
//2022 02 21 18 10
//2022 02 21 19 30

int n, m;
vector<vector<int>> v;

bool thereIsCheese() {
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (v[i][j] == 1) return true;
		}
	}

	return false;
}

void recur1(int c, int r) {
	if (c < 0 || c > n + 1 || r < 0 || r > m + 1) return;
	if (v[c][r] != 0) return;
	v[c][r] = 2;

	recur1(c - 1, r);
	recur1(c, r - 1);
	recur1(c + 1, r);
	recur1(c, r + 1);
}

int main() {

	cin >> n >> m;

	vector<vector<int>>(n + 2, vector<int>(m + 2, 0)).swap(v);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
		}
	}

	int answer = 0;
	while (thereIsCheese()) {
		answer++;
		
		recur1(0, 0);

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				int count = 0;
				if (v[i][j] == 1) {
					if (i > 0 && v[i - 1][j] == 2) count++;
					if (j > 0 && v[i][j - 1] == 2) count++;
					if (i < n + 1 && v[i + 1][j] == 2) count++;
					if (j < m + 1 && v[i][j + 1] == 2) count++;
				}

				if (count >= 2) v[i][j] = -1;
			}
		}

		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				if (v[i][j] != 1) v[i][j] = 0;
			}
		}
	}

	cout << answer;
}