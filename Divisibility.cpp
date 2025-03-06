#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (auto &x : vec) {
        cin >> x;
        x = (x % k + k) % k;
    }

    vector<vector<bool>> f(n, vector<bool>(k, 0));
    f[0][vec[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (f[i - 1][(j + vec[i] + k) % k] || f[i - 1][(j - vec[i] + k) % k]) {
                f[i][j] = true;
            }
        }
    }

    cout << (f[n - 1][0] ? "Divisible\n" : "Not divisible\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}