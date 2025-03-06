#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define F first
#define S second

// sqrt(2 ^ 31) = 46341
constexpr int M = 5E4 + 9;
constexpr int N = 1E6 + 9;
bitset<M> prime; // false -> prime
vector<int> primes;

void sieve() {
    prime[0] = prime[1] = true;
    for (int i = 2; i < M; i++) {
        if (prime[i] == 0) {
            primes.push_back(i);
            for (int j = 2 * i; j < M; j += i) {
                prime[j] = true;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    sieve();

    ll L, R;
    while (cin >> L >> R) {
        bitset<N> vis; // false -> prime
        if (L == 1) vis[0] = true;
        for (auto &p : primes) {
            for (int j = L / p; j <= R / p; j++) {
                if (j > 1 && (p * j - L) >= 0) {
                    vis[p * j - L] = true;
                }
            }
        }

        vector<ll> inter;
        for (int i = 0; i < (R - L + 1); i++){
            if (vis[i] == 0) {
                inter.push_back(L + i);
            }
        }

        if (inter.size() < 2) {
            cout << "There are no adjacent primes.\n";
            continue;
        }

        pii close, far;
        ll mx = 0, mn = 1E18;
        for (int i = 1; i < inter.size(); i++) {
            ll diff = inter[i] - inter[i - 1];
            if (diff < mn) {
                mn = diff;
                close = {inter[i - 1], inter[i]};
            }
            if (diff > mx) {
                mx = diff;
                far = {inter[i - 1], inter[i]};
            }
        }

        cout << close.F << "," << close.S << " are closest, ";
        cout << far.F << "," << far.S << " are most distant.\n";
    }

    return 0;
}