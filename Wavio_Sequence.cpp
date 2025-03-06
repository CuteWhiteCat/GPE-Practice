#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E4 + 9;

int stk[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    while (cin >> n) {
        vector<int> vec(n);
        for (auto &x : vec) {
            cin >> x;
        }

        vector<int> pre(n), suf(n);

        int top = 0;

        for (int i = 0; i < n; i++) {
            auto pos = lower_bound(stk + 1, stk + 1 + top, vec[i]) - stk;
            if (pos == top + 1) {
                top++;
            }
            stk[pos] = vec[i];
            pre[i] = top;
        }

        top = 0;

        for (int i = n - 1; i >= 0; i--) {
            auto pos = lower_bound(stk + 1, stk + 1 + top, vec[i]) - stk;
            if (pos == top + 1) {
                top++;
            }
            stk[pos] = vec[i];
            suf[i] = top;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, min(pre[i], suf[i]) * 2 - 1);
        }

        cout << ans << "\n";
    }

    return 0;
}