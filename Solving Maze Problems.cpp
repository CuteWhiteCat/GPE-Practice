#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct State {
    int x, y;
    vector<pii> path;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    pii S, G;

    vector<string> g(10);
    vector<vector<bool>> vis(10, vector<bool>(10, false));
    for (auto &s : g) {
        cin >> s;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (g[i][j] == 'S') S = {i, j};
            if (g[i][j] == 'G') G = {i, j};
        }
    }

    queue<State> q;
    q.push({S.first, S.second, {S}});
    vis[S.first][S.second] = true;
    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.x == G.first && cur.y == G.second) {
            while (!cur.path.empty()) {
                auto &[x, y] = cur.path.back();
                g[x][y] = '+';
                cur.path.pop_back();
            }
            break;
        }

        for (auto &[dx, dy] : dir) {
            int nx = cur.x + dx;
            int ny = cur.y + dy;

            if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) {
                continue;
            }
            if (vis[nx][ny] || g[nx][ny] == '#') {
                continue;
            }

            State next;
            next.x = nx;
            next.y = ny;
            next.path = cur.path;
            next.path.push_back({nx, ny});
            vis[nx][ny] = true;
            q.push(next);
        }
    }

    for (auto &s : g) {
        cout << s << "\n";
    }

    return 0;
}