#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int p = 0; // pre's position

void postOrder(int l, int r, vector<char> &pre, vector<char> &in, map<char, int> &in_pos) {
    if (l > r) {
        p--;
        return;
    }

    int idx = in_pos[pre[p]];
    p++;
    postOrder(l, idx - 1, pre, in, in_pos);
    p++;
    postOrder(idx + 1, r, pre, in, in_pos);
    
    cout << in[idx] << " ";
}   

void solve() {
    int n;
    cin >> n;

    p = 0;

    vector<char> pre(n), in(n);
    for (auto &x: pre) {
        cin >> x;
    } 
    for (auto &x : in) {
        cin >> x;
    }

    map<char, int> in_pos;
    for (int i = 0; i < n; i++) {
        in_pos[in[i]] = i;
    }

    postOrder(0, n - 1, pre, in, in_pos);
    cout << "\n";
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