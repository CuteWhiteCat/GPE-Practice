#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

void solve() {
    int n;
    cin >> n;
    vector<int> moves;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "LEFT") {
            ans--;
            moves.push_back(-1);
        } else if (s == "RIGHT") {
            ans++;
            moves.push_back(1);
        } else {
            string tmp;
            int idx;
            cin >> tmp >> idx;
            moves.push_back(moves[idx - 1]);
            ans += moves[i];
        }
    }

    cout << ans << "\n";

    return;
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