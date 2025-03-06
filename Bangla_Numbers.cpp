#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll x, string &res) {
    if (x >= 10000000LL) {
        dfs(x / 10000000LL, res);
        res += " kuti";
        x %= 10000000LL;
    }
    if (x >= 100000LL) {
        dfs(x / 100000LL, res);
        res += " lakh";
        x %= 100000LL;
    }
    if (x >= 1000LL) {
        dfs(x / 1000LL, res);
        res += " hajar";
        x %= 1000LL;
    }
    if (x >= 100LL) {
        dfs(x / 100LL, res);
        res += " shata";
        x %= 100LL;
    }
    if (x) {
        if (!res.empty() && res.back() != ' ') {
            res += " ";
        }
        res += to_string(x);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll n;
    int t = 0;
    while (cin >> n) {
        string res = "";
        if (n != 0) {
            dfs(n, res);
        } else {
            res = "0";
        }
        cout << setw(4) << ++t << ". " << res << "\n";
    }

    return 0;
}
