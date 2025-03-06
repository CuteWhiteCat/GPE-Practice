#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

bool check(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void solve() {
    int n, m, q;
    cin >> m >> n >> q;
    cout << m << " " << n << " " << q << "\n";

    vector<string> g(m);
    for (auto &s : g) {
        cin >> s;
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        int layer = 1;
        bool found = true;
        while (found) {
            for (int i = r - layer; i <= r + layer; i++) {
                for (int j = c - layer; j <= c + layer; j++) {
                    if (check(i, j, m, n)) {
                        if (g[i][j] != g[r][c]) {
                            found = false;
                            break;
                        }
                    } else {
                        found = false;
                        break;
                    }
                }
            }

            if (found) {
                layer++;
            }
        }

        layer--;
        cout << 1 + layer * 2 << "\n";
    }
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