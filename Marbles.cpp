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
    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // n1 * x + n2 * y == n
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        ll c1, n1;
        ll c2, n2;
        cin >> c1 >> n1 >> c2 >> n2;

        ll x = 0, y = 0;
        ll g = exgcd(n1, n2, x, y);

        x = x * n / g;
        y = y * n / g;
        ll mn = ceil(-1.0 * x / (1.0 * n2 / g));
        ll mx = floor(1.0 * y / (1.0 * n1 / g));

        if (mn > mx || n % g) {
            cout << "failed\n";
            continue;
        }

        ll m1, m2;
        if (c1 * (x + mn * n2 / g) + c2 * (y - mn * n1 / g) <
            c1 * (x + mx * n2 / g) + c2 * (y - mx * n1 / g)) {
            m1 = x + mn * n2 / g;
            m2 = y - mn * n1 / g;
        } else {
            m1 = x + mx * n2 / g;
            m2 = y - mx * n1 / g;
        }

        cout << m1 << " " << m2 << "\n";
    }

    return 0;
}