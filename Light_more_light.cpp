#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    ll n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        ll m = sqrt(n);
        if (m * m == n) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    
    return 0;
}