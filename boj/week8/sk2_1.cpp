#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> goods) {

	vector<vector<string>> v(goods.size(), vector<string>());

	for (int i = 0; i < goods.size(); i++) {

		for (int j = 1; j <= goods[i].length(); j++) {
			if (v[i].size() > 0) break;

			for (int s = 0; s <= goods[i].length() - j; s++) {
				string temp = goods[i].substr(s, j);
				if (temp.length() != j) continue;

				int flag = 1;
				for (int k = 0; k < goods.size(); k++) {
					if (i == k) continue;

					size_t index = goods[k].find(temp);
					if (index != string::npos) {
						flag = 0;
						break;
					}
				}

				if (flag == 1) v[i].push_back(temp);
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		sort(v[i].begin(), v[i].end());
	}

	vector<string> answer;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].size() == 0) {
			answer.push_back("None");
			continue;
		}

		string temp = "";
		string prev = "";
		for (int j = 0; j < v[i].size(); j++) {
			if (j != 0 && v[i][j] == prev) continue;

			temp += v[i][j] + " ";
			prev = v[i][j];
		}
		if (temp[temp.length() - 1] == ' ') temp.pop_back();
		answer.push_back(temp);
	}

	return answer;
}