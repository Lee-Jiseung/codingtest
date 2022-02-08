#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <deque>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;

		deque<char> left;
		deque<char> right;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '<') {
				if (!left.empty()) {
					char temp = left.back();
					left.pop_back();
					right.push_front(temp);
				}
			}
			else if (s[j] == '>') {
				if (!right.empty()) {
					char temp = right.front();
					right.pop_front();
					left.push_back(temp);
				}
			}
			else if (s[j] == '-') {
				if (!left.empty()) {
					left.pop_back();
				}
			}
			else {
				left.push_back(s[j]);
			}
		}

		/*if (right.size() > 1) {
			char first = right.front();
			right.pop_front();
			char second = right.front();
			right.pop_front();
			left.push_back(second);
			right.push_front(first);
		}
		*/
		for (int j = 0; j < left.size(); j++) {
			cout << left[j];
		}
		for (int j = 0; j < right.size(); j++) {
			cout << right[j];
		}
		cout << '\n';
	}
	return 0;
}