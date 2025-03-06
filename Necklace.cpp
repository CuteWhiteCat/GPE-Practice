#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int V, V0;
    while (cin >> V >> V0) {
        if (V == 0 && V0 == 0) {
            break;
        }

        double x = 1.0 * V / (2 * V0);
        int y = x;
        if (V / round(x) <= V0) {
            cout << "0\n";
        } else if ((x - y) == 0.5) {
            cout << "0\n";
        } else if ((x - y) < 0.5) {
            cout << y << "\n";
        } else {
            cout << y + 1 << "\n";
        }
    }
    
    return 0;
}