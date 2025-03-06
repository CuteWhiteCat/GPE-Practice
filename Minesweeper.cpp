#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    bool first = true;
    
    int n, m;
    int t = 0;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        if (!first) cout << "\n";
        first = false;

        cout << "Field #" << ++t << ":\n";

        vector<string> g(n);
        for (auto &s : g) {
            cin >> s;
        }

        vector<vector<int>> dis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '*') {
                    for (int l = -1; l <= 1; l++) {
                        for (int r = -1; r <= 1; r++) {
                            if (i + l >= n || i + l < 0 || j + r >= m || j + r < 0) {
                                continue;
                            }
                            dis[i + l][j + r]++;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '*') {
                    cout << "*";
                } else {
                    cout << dis[i][j];
                }
            }
            cout << "\n";
        }
    }
    
    return 0;
}