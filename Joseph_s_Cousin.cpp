#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int M = 1E6 + 9;
bitset<M> vis;
vector<int> primes;

void sieve() {
    vis[0] = vis[1] = true;
    for (int i = 2; i < M; i++) {
        if (vis[i] == 0) {
            primes.push_back(i);
            for (int j = i * 2; j < M; j += i) {
                vis[j] = true;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    sieve();

    int N;
    while (cin >> N) {
        if (N == 0) {
            break;
        }

        vector<int> vec(N);
        iota(vec.begin(), vec.end(), 1);
        
        int p = 0;
        for (auto &x : primes) {
            if (vec.size() == 1) {
                break;
            }

            p += x - 1;
            p %= vec.size();
            vec.erase(vec.begin() + p);
        }

        cout << vec[0] << "\n";
    }

    return 0;
}