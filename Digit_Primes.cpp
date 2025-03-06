#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E6 + 9;
bitset<N> vis;
bitset<N> digitPrime;
int pre[N];

bool calc(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }

    if (vis[sum] == 0) {
        return true;
    } else {
        return false;
    }
}

void sieve() {
    vis[0] = vis[1] = 1;
    for (int i = 2; i < N; i++) {
        if (vis[i] == 0) {
            for (int j = 2 * i; j < N; j += i) {
                vis[j] = true;
            }
        }
    }
}

void init() {
    for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
            if (calc(i)) {
                digitPrime[i] = true;
            } else {
                digitPrime[i] = false;
            }
        }
    }

    for (int i = 1; i < N; i++) {
        pre[i] = pre[i - 1] + digitPrime[i];
    }
}

void solve() {
    int L, R;
    cin >> L >> R;
    cout << pre[R] - pre[L - 1] << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    sieve();
    init();

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}