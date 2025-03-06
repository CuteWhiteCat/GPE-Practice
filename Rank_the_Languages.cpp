#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, char>;

constexpr int N = 2E5 + 9;

map<char, int> mp;

int t = 0;
int n, m;

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool cmp(pii &A, pii &B) {
    return A.first == B.first ? A.second < B.second : A.first > B.first;
}

void dfs(int x, int y, vector<vector<char>> &g, vector<vector<bool>> &vis) {
    vis[x][y] = 1;

    vector<pair<int, int>> dir = { {0, 1},
                                   {0, -1},
                                   {1, 0},
                                   {-1, 0} };

    for (auto &[dx, dy] : dir) {
        int nx = x + dx;
        int ny = y + dy;
        if (check(nx, ny) && vis[nx][ny] == 0 && g[nx][ny] == g[x][y]) {
            dfs(nx, ny, g, vis);
        }
    }
}

void solve() {
    cout << "World #" << ++t << "\n";

    cin >> n >> m;

    mp.clear();

    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 0) {
                dfs(i, j, g, vis);
                mp[g[i][j]]++;
            }
        }
    }

    vector<pii> ans;
    for (auto &[x, cnt] : mp) {
        ans.push_back(make_pair(cnt, x));
    }

    sort(ans.begin(), ans.end(), cmp);

    for (auto &[cnt, x] : ans) {
        cout << x << ": " << cnt << "\n";
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