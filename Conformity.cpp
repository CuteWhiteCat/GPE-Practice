#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        map<set<int>, int> mp;
        for (int i = 0; i < n; i++) {
            set<int> tmp;
            for (int j = 0; j < 5; j++) {
                int x;
                cin >> x;
                tmp.insert(x);
            }
            mp[tmp]++;
        }
        
        int ans = 0;
        int mx = 0;
        for (auto &[x, cnt] : mp) {
            mx = max(mx, cnt);
        }
        for (auto &[x, cnt] : mp) {
            if (cnt == mx) {
                ans += cnt;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}