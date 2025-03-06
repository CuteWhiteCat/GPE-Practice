#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int n, m;

bool check(int x, int y, vector<vector<char>> &g) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '@';
}

void dfs(int x, int y, vector<vector<char>> &g) {
    g[x][y] = '*';

    for (auto &dx : {1, 1, 1, -1, -1, -1, 0, 0}) {
        for (auto &dy : {1, -1, 0, 1, -1, 0, 1, -1}) {
            int nx = x + dx;
            int ny = y + dy;
            if (check(nx, ny, g)) {
                dfs(nx, ny, g);
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        vector<vector<char>> g(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '@') {
                    dfs(i, j, g);
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
