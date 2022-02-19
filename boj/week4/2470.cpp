#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 2022 02 12 17 56
// 2022 02 19 14 57

int main() {

	int n;
	cin >> n;

	vector<int> ac;
	vector<int> al;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp > 0) ac.push_back(temp);
		else al.push_back(temp);
	}

	sort(ac.begin(), ac.end());
	sort(al.begin(), al.end());

	if (ac.size() == 0) {
		cout << al[al.size() - 2] << ' ' << al[al.size() - 1];
	}
	else if (al.size() == 0) {
		cout << ac[0] << ' ' << ac[1];
	}
	else {
		int sum = 2000000001;
		int index = 0;
		int small = 0, large = 0;

		if (ac.size() > 1 && al.size()>1 && abs(al[al.size() - 2] + al[al.size() - 1]) > ac[0] + ac[1]) {
			sum = ac[0] + ac[1];
			small = ac[0];
			large = ac[1];
		}
		else if(ac.size() > 1 && al.size() > 1 && abs(al[al.size() - 2] + al[al.size() - 1]) < ac[0] + ac[1]){
			sum = abs(al[al.size() - 2] + al[al.size() - 1]);
			small = al[al.size() - 2];
			large = al[al.size() - 1];
		}

		for (int i = 0; i < al.size(); i++) {
			int temp = -1;
			int prev = 0;

			for (int j = index; j >= 0; j--) {
				int cur = al[i] + ac[j];
				if (abs(cur) < sum) {
					sum = abs(cur);
					temp = j;
					small = al[i];
					large = ac[j];
				}
				else {
					if (prev < 0) break;
				}
				prev = cur;
			}

			prev = 0;
			for (int j = index; j < ac.size(); j++) {
				int cur = al[i] + ac[j];
				if (abs(cur) < sum) {
					sum = abs(cur);
					temp = j;
					small = al[i];
					large = ac[j];
				}
				else {
					if (prev > 0) break;
				}
				prev = cur;
			}
			if (temp != -1) index = temp;
		}
		cout << small << ' ' << large;
	}

	return 0;
}