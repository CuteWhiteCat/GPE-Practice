#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

vector<ll> fac(21);

void init() {
    fac[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fac[i] = fac[i - 1] * i;
    }
}

void solve() {
    string s;
    ll k;
    cin >> s >> k;
    k--;

    int n = s.size();

    string ss = s;
    sort(s.begin(), s.end());

    vector<char> chars;
    for (auto &c : s) {
        chars.push_back(c);
    }
    
    // 假設有1 2 3 4，求第 12 大
    // 如果我們第一個放1 後面排列數 3! 最多大過 6 個數(包括自己)
    // 所以 如果我們放 2 在第 1 位 就會大過 12 個數
    // 所以第一個要放 2
    string res = "";
    for (int i = 0; i < n; i++) {
        ll idx = k / fac[n - i - 1];
        res += chars[idx];
        chars.erase(chars.begin() + idx);
        k %= fac[n - i - 1];
    }

    map<char, char> to;
    for (int i = 0; i < n; i++) {
        to[res[i]] = ss[i];
    }

    for (auto &c : s) {
        cout << to[c];
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    init();

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}