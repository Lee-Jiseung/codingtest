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
// 2022 02 11 15 33
// 2022 02 11 15 57
int main() {

	string s;
	getline(cin, s);

	vector<char> v;
	deque<char> temp;
	int tag = 0;
	auto reverseWord = [&]() {
		for (int j = 0; j < temp.size(); j++) {
			v.push_back(temp[j]);
		}
		deque<char>().swap(temp);
	};
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '<') {
			reverseWord();
			tag = 1;
		}
		else if (s[i] == '>') {
			tag = 0;
		}
		else if (s[i] == ' ') {
			if (tag == 0) {
				reverseWord();
			}
		}
		else {
			if (tag == 0) {
				temp.push_front(s[i]);
				continue;
			}
		}
		v.push_back(s[i]);
	}
	reverseWord();

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	return 0;
}