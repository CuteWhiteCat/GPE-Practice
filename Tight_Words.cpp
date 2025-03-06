#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cout << fixed;

    int k, n;
    while (cin >> k >> n) {
        vector<vector<double>> f(n + 1, vector<double>(k + 1, 0.0));
        for (int i = 0; i <= k; i++) {
            f[1][i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                f[i][j] += f[i - 1][j];
                if (j - 1 >= 0) {
                    f[i][j] += f[i - 1][j - 1];
                }
                if (j + 1 <= k) {
                    f[i][j] += f[i - 1][j + 1];
                }
            }
        }

        double ans = accumulate(f[n].begin(), f[n].end(), 0.0) * 100;
        ans /= pow(k + 1, n);

        cout << setprecision(5) << ans << "\n";
    }

    return 0;
}