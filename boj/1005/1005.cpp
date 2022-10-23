#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2022 02 19 16 14
// 2022 03 06 19 44

int main() {

	int t;
	cin >> t;

	vector<int> answer(t, 0);
	for (int testcase = 0; testcase < t; testcase++) {
		int n, k;
		cin >> n >> k;

		vector<int> delay(n + 1, 0);
		for (int i = 1; i <= n; i++) cin >> delay[i];

		vector<vector<int>> v(n + 1, vector<int>()); // i번째 벡터엔 i번째 건물을 짓기위해 필요한 다른 건물들의 번호가 저장되어있다
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			v[y].push_back(x);
		}

		int w;
		cin >> w;

		vector<int> built(n + 1, 0); // 건물들의 완성 여부를 저장하는 벡터
		vector<int> dp(n + 1, 0); 

		while (built[w] != 1) {
			for (int i = 1; i <= n; i++) {
				if (built[i] != 0) continue;
				int flag = 1;
				int large = 0;
				for (int j = 0; j < v[i].size(); j++) {
					if (built[v[i][j]] == 0) {
						flag = 0;
						break;
					}
					large = max(large, dp[v[i][j]]);
				}

				if (flag == 1) {
					dp[i] = large + delay[i];
					built[i] = 1;
				}
			}
		}

		answer[testcase] = dp[w];
	}

	for (int i = 0; i < t; i++) cout << answer[i] << '\n';
	return 0;
}
