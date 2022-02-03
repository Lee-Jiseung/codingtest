#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stdio.h>
#include <deque>

using namespace std;


int main() {

	int a, b;
	cin >> a >> b;

	int n;
	cin >> n;

	int small = abs(b - a);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		small = min(small, abs(temp - b));
	}

	if (small == abs(b - a)) {
		cout << small;
	}
	else {
		cout << small + 1;
	}
	return 0;
}