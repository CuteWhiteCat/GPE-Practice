#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // 5000000 * 65536 = 327680000000 < 4E18
    ll m, n;
    cin >> m >> n;
    
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    m--;
    n--;

    ll prev = sum;
    while (m--) {
        sum = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            sum += x;
        }
        cout << prev - sum << "\n";
        prev = sum;
        n--;
    }
    
    return 0;
}