#include <iostream>
#include <vector>
#include <deque>

using namespace std;
// 2022 02 12 16 53
// 2022 02 12 17 41

int k;
vector<char> op;
vector<int> v;
int c = 1;

void minTracking() {
	if (c == 0) return;

	int s = v.size();
	if (s == k + 1) {
		for (int i = 0; i < s; i++) {
			cout << v[i];
		}
		cout << '\n';
		c = 0;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		int flag = 1;
		for (int j = 0; j < s; j++) {
			if (i == v[j]) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) continue;

		if (s == 0 || (op[s - 1] == '>' && v[s - 1] > i) || (op[s - 1] == '<' && v[s - 1] < i)) {
			v.push_back(i);
			minTracking();
			v.pop_back();
		}
	}
}
void maxTracking() {
	if (c == 0) return;

	int s = v.size();
	if (s == k + 1) {
		for (int i = 0; i < s; i++) {
			cout << v[i];
		}
		cout << '\n';
		c = 0;
		return;
	}

	for (int i = 9; i >= 0; i--) {
		int flag = 1;
		for (int j = 0; j < s; j++) {
			if (i == v[j]) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) continue;

		if (s == 0 || (op[s - 1] == '>' && v[s - 1] > i) || (op[s - 1] == '<' && v[s - 1] < i)) {
			v.push_back(i);
			maxTracking();
			v.pop_back();
		}
	}
}

int main() {

	cin >> k;
	for (int i = 0; i < k; i++) {
		char temp;
		cin >> temp;
		op.push_back(temp);
	}

	maxTracking();
	
	c = 1;
	vector<int>().swap(v);
	
	minTracking();
	return 0;
}