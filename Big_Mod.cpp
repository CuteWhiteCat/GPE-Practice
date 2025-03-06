#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

ll power(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int B, P, M;
    while (cin >> B >> P >> M) {
        cout << power(B, P, M) << "\n";
    }
    
    return 0;
}