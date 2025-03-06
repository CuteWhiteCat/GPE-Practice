#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E6 + 9;

int t;
string s;

int pre[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    while (cin >> s) {
        cout << "Case " << ++t << ":\n";
        memset(pre, 0, sizeof pre);
        pre[0] = (s[0] == '1');
        for (int i = 1; i < s.size(); i++) {
            pre[i] = pre[i - 1] + (s[i] == '1');
        }

        int q;
        cin >> q;

        while (q--) {
            int l, r;
            cin >> l >> r;
            if (l > r) {
                swap(l, r);
            }
            if (pre[l - 1] == pre[r] || pre[r] - pre[l - 1 ? l - 1 : 0] == r - l + 1){
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}