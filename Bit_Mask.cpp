#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

// 当这个位上为 1 时，为了使 M 尽可能小，我们只在不填 1 就比 L 小的时候填 1，否则填 0。
// 当这个位上为 0 时，为了让值最大，我们只在不填 0 就比 U 大的时候填 0，否则填 1。
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll N, L, U;
    while (cin >> N >> L >> U) {
        bitset<32> n(N), m(0);
        for (int i = 31; i >= 0; i--) {
            m[i] = 1;
            if ((n[i] && m.to_ullong() > L) || m.to_ullong() > U) {
                m[i] = 0;
            }
        }
        cout << m.to_ullong() << "\n";
    }

    return 0;
}