#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int p, q, r;
int x, y, z;
int n;

ll check(ll K, bool type) {
    ll lo = -1;
    ll hi = n;
    while (lo + 1 != hi) {
        ll mid = (lo + hi) >> 1;
        if (type == 0) {
            if ((ll)p * mid * mid + q * mid + r <= K) {
                lo = mid;
            } else {
                hi = mid;
            }
        } else {
            if ((ll)x * mid * mid + y * mid + z <= K) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
    }
    return lo + 1;
}

void solve() {
    cin >> p >> q >> r;
    cin >> x >> y >> z;
    cin >> n;

    ll lastA = ((ll)p * (n - 1) * (n - 1)) + ((ll)q * (n - 1)) + r;
    ll lastB = ((ll)x * (n - 1) * (n - 1)) + ((ll)y * (n - 1)) + z;

    ll lo = min(r, z) - 1;
    ll hi = max(lastA, lastB) + 1;
    while (lo + 1 != hi) {
        ll mid = (lo + hi) >> 1;
        if (check(mid, 0) + check(mid, 1) >= n) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << hi << "\n";
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