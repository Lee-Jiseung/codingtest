#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	int answer = -1;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++) {
		vector<int> temp(n);
		for (int j = 0; j < n; j++) {
			cin >> temp[j];
		}
		v.push_back(temp);
	}


	int k = 0;
	while (k <= n / 2) {
		k++;

		vector<int> team1(n, 0);
		for (int i = 0; i < k; i++) {
			team1[i] = 1;
		}
		sort(team1.begin(), team1.end());

		do {
			int t1 = 0, t2 = 0;
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					if (team1[i] == 0 && team1[j] == 0) {
						t2 += v[i][j] + v[j][i];
					}
					else if (team1[i] == 1 && team1[j] == 1) {
						t1 += v[i][j] + v[j][i];
					}
				}
			}

			int d;
			if (t1 < t2) d = t2 - t1;
			else if (t1 > t2) d = t1 - t2;
			else {
				answer = 0;
				cout << answer;
				return 0;
			}

			if (answer == -1) answer = d;
			else answer = min(answer, d);
		} while (next_permutation(team1.begin(), team1.end()));
	}

	cout << answer;
}