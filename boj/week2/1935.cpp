#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stdio.h>
#include <deque>

using namespace std;


int main() {

	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<double> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	deque<double> d;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			d.push_back(v[s[i] - 65]);
		}
		else {
			double second = d.back();
			d.pop_back();
			double first = d.back();
			d.pop_back();

			if (s[i] == '+') {
				d.push_back(first + second);
			}
			else if (s[i] == '-') {
				d.push_back(first - second);
			}
			else if (s[i] == '*') {
				d.push_back(first * second);
			}
			else if (s[i] == '/') {
				d.push_back(first / second);
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << d.back();
	return 0;
}