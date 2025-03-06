#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll S, D;
    while (cin >> S >> D) {
        cout << S + (ll)ceil(
                        sqrt(4.0 * S * S + 8 * D - 4 * S + 1) / 2 - S - 0.5)
             << "\n";
    }

    return 0;
}