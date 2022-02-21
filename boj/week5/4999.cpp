#include <iostream>
#include <string>

using namespace std;
//2022 02 21 16 36
//2022 02 21 16 38

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	if (s1.length() >= s2.length()) cout << "go";
	else cout << "no";
}