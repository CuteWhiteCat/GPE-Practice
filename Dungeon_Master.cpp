#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

constexpr int N = 32;

struct Node {
    int x, y, z;
    int step;
};

char g[N][N][N];
int dis[N][N][N];
bool vis[N][N][N];

int L, R, C;
tii st, ed;

vector<tii> dir = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

bool check(int x, int y, int z) {
    return x >= 1 && x <= R && y >= 1 && y <= C && z >= 1 && z <= L && g[x][y][z] != '#';
}

int bfs() {
    queue<Node> q;
    auto &[a, b, c] = st;
    q.push({a, b, c, 0});
    vis[a][b][c] = true;
    
    while (!q.empty()) {
        auto [x, y, z, step] = q.front();
        auto [Fx, Fy, Fz] = ed;
        q.pop();

        if (x == Fx && y == Fy && z == Fz) {
            return step;
        }

        for (auto &[dx, dy, dz] : dir) {
            int nx = x + dx;
            int ny = y + dy;
            int nz = z + dz;

            if (check(nx, ny, nz) && !vis[nx][ny][nz]) {
                q.push({nx, ny, nz, step + 1});
                vis[nx][ny][nz] = true;
            }
        }
    }   

    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (cin >> L >> R >> C) {
        if (L == 0 && R == 0 && C == 0) {
            break;
        }

        memset(g, 0, sizeof g);
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);

        for (int k = 1; k <= L; k++) {
            for (int i = 1; i <= R; i++) {
                for (int j = 1; j <= C; j++) {
                    cin >> g[i][j][k];
                    if (g[i][j][k] == 'S') {
                        st = {i, j, k};
                    }
                    if (g[i][j][k] == 'E') {
                        ed = {i, j, k};
                    }
                }
            }
        }

        int ans = bfs();
        if (ans == -1) {
            cout << "Trapped!\n";
        } else {
            cout << "Escaped in " << ans << " minute(s).\n";
        }
    }

    return 0;
}