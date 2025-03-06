#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 350;

struct State {
    int x, y;
    int lastStep;  // 0: 1, 1: 2, 2: 3
    int step;
};

int n, m;
pii S, E;

char g[N][N];
bool vis[N][N][3];

vector<pii> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs() {
    queue<State> q;
    q.push({S.first, S.second, 0, 0});
    vis[S.first][S.second][0] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.x == E.first && cur.y == E.second) {
            return cur.step;
        }

        int k = (cur.lastStep % 3) + 1;
        for (auto &[dx, dy] : dir) {
            int nx = cur.x + dx * k;
            int ny = cur.y + dy * k;

            bool ok = true;
            for (int i = 1; i <= k; i++) {
                int tmpx = cur.x + dx * i;
                int tmpy = cur.y + dy * i;
                if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m || g[tmpx][tmpy] == '#') {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            int m = (cur.lastStep + 1) % 3;
            if (!vis[nx][ny][m]) {
                vis[nx][ny][m] = true;
                q.push({nx, ny, m, cur.step + 1});
            }
        }
    }

    return -1;
}

void solve() {
    memset(vis, false, sizeof vis);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'S') S = {i, j};
            if (g[i][j] == 'E') E = {i, j};
        }
    }

    int ans = bfs();

    if (ans == -1) {
        cout << "NO\n";
    } else {
        cout << ans << "\n";
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