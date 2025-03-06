#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int min_expr(string s) {
    int n = s.size();
    s += s;
    int i = 0, j = 1;
    while (i < n && j < n) {
        int k = 0;
        while (k < n && s[i + k] == s[j + k]) {
            ++k;
        }
        s[i + k] > s[j + k] ? i += k + 1 : j += k + 1;
        if (i == j) j++;
    }
    return min(i, j);
}

void solve() {
    string s;
    cin >> s;
    cout << min_expr(s) + 1 << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}