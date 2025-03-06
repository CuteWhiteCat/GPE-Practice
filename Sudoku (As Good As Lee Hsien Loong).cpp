#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 9;

vector<vector<int>> g(N, vector<int>(N));
pii pos;

pii isEmpty() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (g[i][j] == 0) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

bool check(int x, int y, int v) {
    for (int i = 0; i < N; i++) {
        if (g[x][i] == v || g[i][y] == v) {
            return false;
        }
    }

    int row = x - x % 3;
    int col = y - y % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (g[row + i][col + j] == v) {
                return false;
            }
        }
    }

    return true;
}

bool check() {
    pii pos = isEmpty();
    int i = pos.first;
    int j = pos.second;
    if (i == -1 && j == -1) {
        return true;
    }

    for (int x = 1; x <= 9; x++) {
        if (check(i, j, x)) {
            g[i][j] = x;
            if (check()) {
                return true;
            }
            g[i][j] = 0;
        }
    }

    return false;
}

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> g[i][j];
        }
    }

    if (check()) {
        for (auto &v : g) {
            for (auto &x : v) {
                cout << x << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "NO\n";
    }

    return;
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