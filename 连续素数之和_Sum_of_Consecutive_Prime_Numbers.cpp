#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E4 + 9;
vector<int> primes;
bitset<N> vis;

int pre[N];

void init() {
    for (int i = 2; i <= N; i++) {
        if (vis[i] == 0) {
            primes.push_back(i);
        }
        for (int j = i; j <= N; j += i) {
            vis[j] = true;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    init();

    for (int i = 1; i <= primes.size(); i++) {
        pre[i] = pre[i - 1] + primes[i - 1];
    }

    int x;
    while (cin >> x) {
        if (x == 0) {
            break;
        }

        int n = primes.size();
        ll ans = 0;

        // Brute Force
        // for (int l = 1; l <= n; l++) {
        //     for (int r = l; r <= n; r++) {
        //         if (pre[r] - pre[l - 1] == x) {
        //             ans++;
        //         }
        //     }
        // }

        // Two Pointer
        int l = 1, r = 1;
        while (r <= n) {
            int sum = pre[r] - pre[l - 1];
            if (sum == x) {
                ans++;
                r++;
            } else if (sum < x) {
                r++;
            } else {
                l++;
                if (l > r) {
                    r = l;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}