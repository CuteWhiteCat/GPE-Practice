#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E4;  
bitset<N> vis;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        vis.reset();
        
        ll ans = 0;
        while (!vis[n]) {
            vis[n] = 1;
            ans++;
            n = n * n / 100 % 10000;
        }

        cout << ans << "\n";
    }
    
    return 0;
}