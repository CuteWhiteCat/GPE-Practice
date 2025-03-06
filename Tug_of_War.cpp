#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 45010;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &x : vec) {
        cin >> x;
    }

    ll tot = accumulate(vec.begin(), vec.end(), 0LL);
    vector<ull> f(tot + 1, 0);
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = tot; j >= vec[i]; j--) {
            f[j] |= f[j - vec[i]] << 1;
        }
    }

    int A = 1E9, B = 0;
    for (int i = 0; i <= tot; i++) {
        for (int j = 0; j <= (n + 1) / 2; j++) {
            if (f[i] & (1LL << j) && abs(j * 2 - n) <= 1) {
                if (abs(tot - 2 * i) < A - B) {
                    A = max((ll)i, tot - i);
                    B = tot - A;
                }
            }
        }
    }
    
    cout << B << " " << A << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    bool first = true;

    int T;
    cin >> T;
    while (T--) {
        if (!first) {
            cout << "\n";
        }
        first = false;
        solve();
    }
    
    return 0;
}