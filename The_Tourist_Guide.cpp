#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 110;

int f[N];

struct Edge {
    int u, v, w;

    bool operator<(const Edge &oth) const {
        return w > oth.w;
    }
};

void init(int n) {
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
}

int find(int x) {
    return f[x] = (f[x] == x ? x : find(f[x]));
}

bool match(int x, int y) {
    int fx = find(x);
    int fy = find(y);

    if (fx == fy) {
        return true;
    } else {
        return false;
    }
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);

    if (fx == fy) return;
    f[fx] = fy;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    int t = 0;
    bool first = true;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        cout << "Scenario #" << ++t << "\n";

        vector<Edge> g;
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g.push_back({u, v, w});
        }

        int S, T, tot;
        cin >> S >> T >> tot;

        sort(g.begin(), g.end());

        init(n);
        int mn = 0;
        for (int i = 0; i < m; i++) {
            auto &[u, v, w] = g[i];
            merge(u, v);
            mn = w;
            if (match(S, T)) {
                break;
            }
        }
        mn--;

        cout << "Minimum Number of Trips = ";
        if (tot % mn) {
            cout << tot / mn + 1 << "\n";
        } else {
            cout << tot / mn << "\n";
        }
        cout << "\n";
    }

    return 0;
}