#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

constexpr int N = 2E5 + 9;
constexpr int INF = 1E9;

int n, m;

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check(i - 1, j) && check(i, j - 1)) {
                g[i][j] += min(g[i - 1][j], g[i][j - 1]);
            } else if (check(i - 1, j)) {
                g[i][j] += g[i - 1][j];
            } else if (check(i, j - 1)) {
                g[i][j] += g[i][j - 1];
            }
        }
    }

    n--;
    m--;
    cout << g[n][m] << "\n";
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