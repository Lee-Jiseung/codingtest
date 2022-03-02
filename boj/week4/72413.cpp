#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    vector<vector<int>> f(n + 1, vector<int>(n + 1, 20000001));
    for (int i = 0; i < fares.size(); i++) {
        f[fares[i][0]][fares[i][1]] = fares[i][2];
        f[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for (int i = 0; i <= n; i++) f[i][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                f[j][k] = min(f[j][k], f[j][i] + f[i][k]);
            }
        }
    }

    int answer = 20000001;
    for (int i = 1; i <= n; i++) {
        answer = min(answer, f[s][i] + f[i][a] + f[i][b]);
    }

    return answer;
}