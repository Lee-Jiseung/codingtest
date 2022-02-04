#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stdio.h>
#include <stack>

using namespace std;


int main() {

	long long n;
	cin >> n;

	long long temp = n;
	int k = 0;
	while (temp/2 > 0) {
		temp /= 2;
		k++;
	}

	for (int i = k; i >= 0; i--) {
		if (n >= (long long) pow(2, i)) {
			n -= (long long)pow(2, i);
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	return 0;
}