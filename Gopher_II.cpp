#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<double, double>;

constexpr int N = 1E3 + 9;
bitset<N> vis;
vector<int> match(N, -1);
vector<int> adj[N];

int n, m;
double s, v;

void init() {
    for (int i = 0; i < N; i++) {
        adj[i].clear();
        match[i] = -1;
    }
}

bool dfs(int x) {
    for (auto &y : adj[x]) {
        if (vis[y]) continue;
        vis[y] = true;
        if (match[y] == -1 || dfs(match[y])) {
            match[y] = x;
            return true;
        }
    }
    return false;
}

void solve() {
    double S = s * v;

    vector<pii> vec(n + m);
    for (int i = 0; i < (n + m); i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    for (int i = 0; i < n; i++) {
        for (int j = n; j < n + m; j++) {
            double dist = hypot(vec[j].first - vec[i].first,
                                vec[j].second - vec[i].second);
            if (dist <= S) {
                adj[i].push_back(j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vis.reset();
        if (dfs(i)) ans++;
    }

    cout << n - ans << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (cin >> n >> m >> s >> v) {
        init();
        solve();
    }

    return 0;
}