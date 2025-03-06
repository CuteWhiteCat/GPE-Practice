#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 128;

int n, t;
int S, T;

int dis[N][N];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        memset(dis, 0x3f, sizeof dis);
        for (int i = 1; i <= n; i++) {
            dis[i][i] = 0;
        }

        cin >> S;
        cout << "Case " << ++t << ": The longest path from " << S << " has length ";

        int p, q;
        while (cin >> p >> q) {
            if (p == 0 && q == 0) {
                break;
            }
            dis[p][q] = -1;
        }

        floyd();

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (ans > dis[S][i]) {
                ans = dis[S][i];
                T = i;
            }
        }

        cout << -ans << ", finishing at " << T << ".\n";
        cout << "\n";
    }

    return 0;
}