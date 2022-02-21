#include <iostream>
#include <vector>

using namespace std;
//2022 02 21 16 40
//2022 02 21 17 45

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}

	int answer = 0;
	vector<int> f(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		if (v[1][i] == 1 && f[i] == 0) {
			answer++;
			f[i] = 1;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (f[i] == 1) {
			for (int j = 2; j <= n; j++) {
				if (f[j] == 0 && v[i][j] == 1) {
					answer++;
					f[j] = 2;
				}
			}
		}
	}
	cout << answer;
}