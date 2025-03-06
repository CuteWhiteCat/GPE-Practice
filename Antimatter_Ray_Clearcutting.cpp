#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define F first
#define S second

constexpr int N = 1 << 20;

int f[N];

int bitmask;
int n, m;
int t;

int dfs(int now, vector<vector<int>> &g) {
    int cnt = __builtin_popcount(now);
    if (cnt <= n - m) {
        return f[now] = 0;
    }
    if (cnt == 1) {
        return f[now] = 1;
    }
    if (f[now] != -1) {
        return f[now];
    }

    int res = 1E9;
    for (int i = 0; i < n; i++) {
        if ((1LL << i) & now) {
            for (int j = i + 1; j < n; j++) {
                if ((1LL << j) & now) {
                    int tmp = now & (g[i][j] ^ bitmask);
                    res = min(res, dfs(tmp, g) + 1);
                }
            }
        }
    }

    return f[now] = res;
}

void solve() {
    memset(f, -1, sizeof f);
    cin >> n >> m;

    vector<pii> vec(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec[i] = {x, y};
    }

    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || (vec[i].F == vec[j].F && vec[i].S == vec[j].S)) {
                continue;
            }

            for (int k = n - 1; k >= 0; k--) {
                g[i][j] <<= 1;
                if ((vec[j].F - vec[i].F) * (vec[k].S - vec[j].S) ==
                    (vec[k].F - vec[j].F) * (vec[j].S - vec[i].S)) {
                        g[i][j]++;
                }
            }
        }
    }

    bitmask = (1 << n) - 1;
    cout << dfs(bitmask, g) << "\n";
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
        cout << "Case #" << ++t << ":\n";
        solve();
    }

    return 0;
}