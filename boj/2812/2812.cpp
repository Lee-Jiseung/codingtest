#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stdio.h>
#include <deque>

using namespace std;

int n, k;
string s;
deque<char> d;


int main() {

	cin >> n >> k;
	cin >> s;

	

	for (int i = 0; i < n; i++) {
		while (!d.empty() && k > 0 && d.back() < s[i]) {
			d.pop_back();
			k--;
		}
		d.push_back(s[i]);
	}

	for (int i = 0; i < (d.size()-k); i++) {
		cout << d[i];
	}
	return 0;
}