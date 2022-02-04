#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stdio.h>
#include <deque>

using namespace std;


int main() {

	string name;
	cin >> name;
	int n;
	cin >> n;

	vector<int> v(4, 0);
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == 'L') {
			v[0]++;
		}
		else if (name[i] == 'O') {
			v[1]++;
		}
		else if (name[i] == 'V') {
			v[2]++;
		}
		else if (name[i] == 'E') {
			v[3]++;
		}
	}

	int score = 0;
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		
		vector<int> v2 = { v.begin(), v.end() };
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == 'L') {
				v2[0]++;
			}
			else if (temp[j] == 'O') {
				v2[1]++;
			}
			else if (temp[j] == 'V') {
				v2[2]++;
			}
			else if (temp[j] == 'E') {
				v2[3]++;
			}
		}

		int tempscore = ((v2[0] + v2[1]) * (v2[0] + v2[2]) * (v2[0] + v2[3]) * (v2[1] + v2[2]) * (v2[1] + v2[3]) * (v2[2] + v2[3])) % 100;

		if (tempscore == score) {
			answer.push_back(temp);
		}
		else if (tempscore > score) {
			score = tempscore;
			vector<string>().swap(answer);
			answer.push_back(temp);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer[0];
	return 0;
}