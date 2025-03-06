#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

set<vector<ll>> ans;

void dfs(vector<ll> &cur, vector<ll> &vec, int pos) {
    if (!cur.empty()) {
        ans.insert(cur);
    }

    if (pos == vec.size()) {
        return;
    }

    for (int i = pos; i < vec.size(); i++) {
        if (cur.empty()) {
            cur.push_back(vec[i]);
            dfs(cur, vec, i + 1);
            cur.pop_back();
        } else if (vec[i] > cur.back()) {
            cur.push_back(vec[i]);
            dfs(cur, vec, i + 1);
            cur.pop_back();
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<ll> vec(n);
    for (auto &x : vec) {
        cin >> x;
    }

    ans.clear();
    vector<ll> cur;
    dfs(cur, vec, 0);

    int mx = 0;
    for (auto &x : ans) {
        mx = max(mx, (int)x.size());
    }

    vector<vector<ll>> remove; 
    for (auto &x : ans) {
        if (x.size() < mx) {
            remove.push_back(x);
        }
    }

    for (auto &x : remove) {
        ans.erase(x);
    }

    cout << ans.size() << "\n";
    for (auto &v : ans) {
        for (auto &x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }
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