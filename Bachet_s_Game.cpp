#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E6 + 9;
bool f[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        vector<int> moves(m);
        for (auto &x : moves) {
            cin >> x;
        }

        fill(f, f + 1 + n, 0);

        for (int i = 0; i <= n; i++) {
            if (f[i] == 0) {
                for (auto &x : moves) {
                    if (i + x <= n) {
                        f[i + x] = 1;
                    }
                }
            }
        }

        cout << (f[n] ? "Stan wins\n" : "Ollie wins\n");
    }

    return 0;
}