#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;
constexpr int INF = 1E9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        ll sum = 0, ans = -INF;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            sum = max(x, sum + x);
            ans = max(ans, sum);
        }
        
        if (ans <= 0) {
            cout << "Losing streak.\n";
        } else {
            cout << "The maximum winning streak is " << ans << ".\n";
        }
    }
    
    return 0;
}