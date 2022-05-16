#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//2022 05 02 16 52
//2022 05 02 18 30

int main() {
    // boj 15658

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> op(4, 0);
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    int biggest = -1000000000, smallest = 1000000000;
    for (int i = 0; i <= n-1; i++) {
        if (i > op[0]) {
            break;
        }
        for (int j = 0; j <= n - 1 - i; j++) {
            if (j > op[1]) {
                break;

            }
            for (int k = 0; k <= n - 1 - i - j; k++) {
                int l = n - 1 - i - j - k;
                if (k > op[2] || l > op[3]) {
                    continue;
                }

                vector<int> add(n - 1, 0);
                for (int i0 = 0; i0 < i; i0++) {
                    add[i0] = 1;
                }
                vector<int> sub(n - 1 - i, 0);
                for (int i0 = 0; i0 < j; i0++) {
                    sub[i0] = 1;
                }
                vector<int> mul(n - 1 - i - j, 0);
                for (int i0 = 0; i0 < k; i0++) {
                    mul[i0] = 1;
                }
                sort(add.begin(), add.end());
                sort(sub.begin(), sub.end());
                sort(mul.begin(), mul.end());

                do {
                    do {
                        do {
                            int temp = v[0];
                            for (int i0 = 0, i1 = 0, i2 = 0; i0 < n - 1; i0++) {
                                if (add[i0]) {
                                    temp += v[i0 + 1];
                                }
                                else if (sub[i1]) {
                                    i1++;
                                    temp -= v[i0 + 1];
                                }
                                else if (mul[i2]) {
                                    i1++, i2++;
                                    temp *= v[i0 + 1];
                                }
                                else {
                                    i1++, i2++;
                                    temp /= v[i0 + 1];
                                }
                            }
                            
                            biggest = max(biggest, temp);
                            smallest = min(smallest, temp);
                        } while (next_permutation(mul.begin(), mul.end()));
                    } while (next_permutation(sub.begin(), sub.end()));
                } while (next_permutation(add.begin(), add.end()));
            }
        }
    }

    cout << biggest << '\n' << smallest;
    return 0;
}