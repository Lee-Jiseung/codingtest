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

void makeBigger(int start, int count) {
	if (s.size() == n - k) return;

	char large = s[start];
	int index = start;
	for (int i = start; i <= k - count + start; i++) {
		//cout << i<<' '<<count<<' '<<start<<' '<< k - count + start<<'\n';
		if (large < s[i]) {
			large = s[i];
			index = i;
			break;
		}
	}

	if (index > start) {
		s.erase(start, 1);
		makeBigger(start, count + 1);
	}
	else {
		makeBigger(start + 1, count);
	}

}

int main() {

	cin >> n >> k;
	cin >> s;

	makeBigger(0, 0);

	cout << s;
	return 0;
}