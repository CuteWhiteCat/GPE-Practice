#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

#include <xor/debug>

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    while (cin >> n) {
        if (n == 1) {
            cout << "0 0\n";
            continue;
        }
        int tot = 1;
        int layer = 0;
        while (n > tot) {
            n -= tot;
            layer++;
            tot = layer * 6;
        }

        int x = 0, y = 0;
        if (n <= layer) {
            x = layer - n;
            y = n;
        } else if (n <= layer * 2) {
            x = layer - n;
            y = layer;
        } else if (n <= layer * 3) {
            x = -layer;
            y = layer - (n - layer * 2);
        } else if (n <= layer * 4) {
            x = -layer + (n - layer * 3);
            y = -(n - layer * 3);
        } else if (n <= layer * 5) {
            x = n - layer * 4;
            y = -layer;
        } else {
            x = layer;
            y = -layer + (n - layer * 5);
        }

        cout << x << " " << y << "\n";
    }

    return 0;
}