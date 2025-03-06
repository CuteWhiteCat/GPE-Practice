#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int m, n, t;
    while (cin >> m >> n >> t) {
        vector<int> f(t + 1, -1);
        f[0] = 0;

        vector<int> times{m, n};
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= t; j++) {
                if (j - times[i] >= 0 && f[j - times[i]] != -1) {
                    f[j] = max(f[j], f[j - times[i]] + 1);
                }
            }
        }

        int ans = 0, remain = t;
        for (int i = t; i >= 1; i--) {
            if (f[i] == -1) continue;
            if (t - i < remain) {
                ans = f[i];
                remain = t - i;
            }
        }

        if (remain) {
            cout << ans << " " << remain << "\n";
        } else {
            cout << ans << "\n";
        }
    }

    return 0;
}