#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int pattern[11][3][5] = {
    {{1, 0, 0, 0, 0},
     {1, 1, 1, 1, 0},
     {1, 0, 0, 0, 0}},

    {{1, 0, 0, 0, 0},
     {1, 1, 1, 1, 0},
     {0, 1, 0, 0, 0}},

    {{1, 0, 0, 0, 0},
     {1, 1, 1, 1, 0},
     {0, 0, 1, 0, 0}},

    {{1, 0, 0, 0, 0},
     {1, 1, 1, 1, 0},
     {0, 0, 0, 1, 0}},

    {{0, 1, 0, 0, 0},
     {1, 1, 1, 1, 0},
     {0, 1, 0, 0, 0}},

    {{0, 1, 0, 0, 0},
     {1, 1, 1, 1, 0},
     {0, 0, 1, 0, 0}},

    {{1, 1, 0, 0, 0},
     {0, 1, 1, 1, 0},
     {0, 1, 0, 0, 0}},

    {{1, 1, 0, 0, 0},
     {0, 1, 1, 1, 0},
     {0, 0, 1, 0, 0}},

    {{1, 1, 0, 0, 0},
     {0, 1, 1, 1, 0},
     {0, 0, 0, 1, 0}},

    {{1, 1, 1, 0, 0},
     {0, 0, 1, 1, 1},
     {0, 0, 0, 0, 0}},

    {{1, 1, 0, 0, 0},
     {0, 1, 1, 0, 0},
     {0, 0, 1, 1, 0}}};

int g[6][6];

void rotate() {
    int tmp[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            tmp[i][j] = g[5 - j][i];
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            g[i][j] = tmp[i][j];
        }
    }
}

void mirror() {
    int tmp[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            tmp[i][j] = g[i][5 - j];
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            g[i][j] = tmp[i][j];
        }
    }
}

bool check() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 11; k++) {
                bool ok = true;
                for (int p = 0; p < 3 && ok; p++) {
                    for (int q = 0; q < 5 && ok; q++) {
                        if (pattern[k][p][q] == 0) continue;
                        if (i + p >= 6 || j + q >= 6 || g[i + p][j + q] != pattern[k][p][q]) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) return true;
            }
        }
    }
    return false;
}

bool work() {
    // 每次鏡像，旋轉四次
    for (int i = 1; i <= 2; i++) {
        mirror();
        for (int j = 1; j <= 4; j++) {
            if (check()) {
                return true;
            }
            rotate();
        }
    }
    return false;
}

void solve() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> g[i][j];
        }
    }

    if (work()) {
        cout << "correct\n";
    } else {
        cout << "incorrect\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    bool first = true;

    int T;
    cin >> T;
    while (T--) {
        if (!first) {
            cout << "\n";
        }
        first = false;
        solve();
    }

    return 0;
}