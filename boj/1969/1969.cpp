#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> countN(4, 0);
	string neu = "ACGT";
	string answer;
	int d = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			switch (v[j][i])
			{
			case 'A':
				countN[0]++;
				break;
			case 'C':
				countN[1]++;
				break;
			case 'G':
				countN[2]++;
				break;
			case 'T':
				countN[3]++;
				break;
			default:
				break;
			}
		}

		int max = countN[0], maxIndex = 0, sum = countN[0];
		for (int j = 1; j < 4; j++) {
			if (max < countN[j]) {
				maxIndex = j;
				max = countN[j];
			}
			sum += countN[j];
		}

		answer += neu[maxIndex];
		d += sum - max;

		for (int j = 0; j < 4; j++) {
			countN[j] = 0;
		}
	}

	cout << answer << endl << d << endl;
}