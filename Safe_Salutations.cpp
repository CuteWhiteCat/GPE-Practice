#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;
ll fac[N];

void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i;
    }
}

ll binom(ll n, ll m) {
    if (m > n) {
        return 0;
    } else {
        return fac[n] / (fac[m] * fac[n - m]);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    init();

    ll n;
    bool first = true;
    while (cin >> n) {
        if (!first) {
            cout << "\n";
        }
        cout << binom(2 * n, n) / (n + 1) << "\n";
        first = false;
    }

    return 0;
}