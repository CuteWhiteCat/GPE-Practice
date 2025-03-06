#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int A, B;
    while (cin >> A >> B) {
        ll x, y;
        int D = exgcd(A, B, x, y);
        cout << x << " " << y << " " << D << "\n";
    }

    return 0;
}