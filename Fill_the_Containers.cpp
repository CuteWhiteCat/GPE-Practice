#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E6 + 9;
constexpr ll INF = 1E18;

int a[N];
int n, m;

ll check(ll mid) {
    ll sum = 0, cnt = 1;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (sum > mid) {
            sum = a[i];
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (cin >> n >> m) {
        fill(a + 1, a + 1 + n, 0);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        ll tot = accumulate(a + 1, a + 1 + n, 0LL);
        ll mx = *max_element(a + 1, a + 1 + n);
        ll lo = mx - 1, hi = tot + 1;

        while (lo + 1 != hi) {
            ll mid = (lo + hi) >> 1;
            if (check(mid) <= m) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        cout << hi << "\n";
    }

    return 0;
}
