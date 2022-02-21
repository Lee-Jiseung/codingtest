#include <iostream>
#include <vector>

using namespace std;
//2022 02 21 19 32
//2022 02 21 20 02

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		
		vector<int> temp(num, 0);
		for (int j = 0; j < num; j++) {
			cin >> temp[j];
		}

		for (int j = 1; j < num; j++) {
			for (int k = 0; k < j; k++) {
				v[temp[j]][temp[k]] = 1;
			}
		}
	}

	vector<int> answer(n+1, 0);
	int count = 1;
	while (count <= n) {
		int temp = count;

		for (int i = 1; i <= n; i++) {
			if (answer[i] != 0) continue;
			int flag = 1;
			for (int j = 1; j <= n; j++) {
				if (v[i][j] == 1 && answer[j] == 0) {
					flag = 0;
					break;
				}
			}

			if (flag == 1) {
				answer[i] = count++;
				break;
			}
		}

		if (temp == count) {
			cout << 0;
			return 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (answer[j] == i) {
				cout << j << '\n';
				break;
			}
		}
	}
}