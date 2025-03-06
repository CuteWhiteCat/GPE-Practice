#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

struct Edge {
    int v, w;
};

vector<Edge> adj[N];

int ans = 0;

int dfs(int u, int fa) {
    int d1 = 0, d2 = 0;
    for (auto &[v, w] : adj[u]) {
        if (v == fa) {
            continue;
        }
        int d = dfs(v, u) + w;
        if (d >= d1) {
            d2 = d1;
            d1 = d;
        } else if (d > d2) {
            d2 = d;
        }
    }
    ans = max(ans, d1 + d2);
    return d1;
}

void solve() {
    ans = 0;
    dfs(1, 0);
    cout << ans << "\n";
    for (auto &x : adj) {
        x.clear();
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string buffer;
    while (getline(cin, buffer)) {
        if (buffer.size() == 0) {
            solve();
        }

        stringstream ss(buffer);
        int u, v, w;
        while (ss >> u >> v >> w) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    solve();

    return 0;
}