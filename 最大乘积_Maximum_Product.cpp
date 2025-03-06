#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    bool first = true;

    int n;
    while (cin >> n) {
        cout << "Case #" << ++t << ": The maximum product is ";

        vector<int> vec(n);
        for (auto &x : vec) {
            cin >> x;
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll prod = 1;
            for (int j = i; j < n; j++) {
                prod *= vec[j];
                ans = max(ans, prod);
            }
        }

        cout << ans << ".\n";
        cout << "\n";
    }

    return 0;
}