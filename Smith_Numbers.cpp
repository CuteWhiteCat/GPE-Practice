#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 5E4 + 9;
bitset<N> vis;
vector<int> primes;

void init() {
    vis[0] = vis[1] = 1;
    for (int i = 2; i < N; i++) {
        if (vis[i] == 0) {
            primes.push_back(i);
            for (int j = i * 2; j < N; j += i) {
                vis[j] = true;
            }
        }
    }
}

int calc(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

bool isPrime(int x) {
    if (x < N) {
        return !vis[x];
    }
    for (auto &p : primes) {
        if (1LL * p * p > x) {
            break;
        }
        if (x % p == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    for (int i = n + 1;; i++) {
        if (isPrime(i)) {
            continue;
        }

        int tmp = i, sum = 0;
        for (int j = 2; j * j <= tmp; j++) {
            if (tmp % j == 0) {
                while (tmp % j == 0) {
                    tmp /= j;
                    sum += calc(j);
                }
            }
        }

        if (tmp > 1) {
            sum += calc(tmp);
        }

        if (sum == calc(i)) {
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    init();

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}