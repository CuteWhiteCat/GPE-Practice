#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + g[i][j];
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int h = 1; h <= i; h++) {
                    for (int w = 1; w <= j; w++) {
                        if (pre[i][j] - pre[i - h][j] - pre[i][j - w] + pre[i - h][j - w]  == 0) {
                            ans = max(ans, h * w);
                        }
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}