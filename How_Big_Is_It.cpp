#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

double dis(double a, double b) {
    return 2 * sqrt(a * b);
}

void solve() {
    int n;
    cin >> n;
    vector<double> radius(n);
    for (auto &x : radius) {
        cin >> x;
    }

    sort(radius.begin(), radius.end());

    double ans = 4E18;
    do {
        vector<double> pos(radius.begin(), radius.end());
        // 考慮到現在枚舉的圓可能會跟上上個圓(或之前)的圓才相切
        // 所以要取 max (兩圓水平距 + 之前相切圓的座標)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                double cur = dis(radius[i], radius[j]) + pos[j];
                pos[i] = max(pos[i], cur);
            }
        }

        // 同樣道理，所以答案會是max (圓半徑 + 座標)
        double mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, radius[i] + pos[i]);
        }

        ans = min(ans, mx);
    } while (next_permutation(radius.begin(), radius.end()));

    cout << setprecision(3) << ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed;

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}