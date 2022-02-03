#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Station {
public:
	int index;
	int price;
	Station(int index, int price) :index(index), price(price) {}
};

bool compare(Station s1, Station s2) {
	if (s1.price == s2.price) {
		return s1.index > s2.index;
	}
	else {
		return s1.price < s2.price;
	}
}

int main() {
	int n;
	cin >> n;

	vector<long long> d(1, 0);
	long long sum = 0;
	for (int i = 0; i < n - 1; i++) {
		long long temp;
		cin >> temp;
		sum += temp;
		d.push_back(sum);
	}

	vector<Station> s;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (i != n - 1) {
			s.push_back(Station(i, temp));
		}
	}

	sort(s.begin(), s.end(), compare);

	long long answer = 0;
	int done = n-1;
	for (int i = 0; i < n-1; i++) {
		
		int index = s[i].index;
		if (done > index) {
			answer += (d[done] - d[index]) * s[i].price;
			done = index;
		}
		if (done == 0) {
			break;
		}
	}

	cout << answer;
}