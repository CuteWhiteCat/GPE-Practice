#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define f first
#define s second

constexpr int N = 2E5 + 9;

void solve() {
    int M;
    cin >> M;

    vector<pii> segments;
    int L, R;
    while (cin >> L >> R) {
        if (L == 0 && R == 0) {
            break;
        }
        segments.push_back({L, R});
    }

    sort(segments.begin(), segments.end());

    vector<pii> ans;
    int l = 0, r = 0;
    int n = segments.size();
    for (int i = 0; i < n; i++) {
        int p = -1;
        while (i < n && segments[i].f <= l) {
            if (segments[i].s > r) {
                r = segments[i].s;
                p = i;
            }
            i++;
        }
        i--;

        if (p == -1) {
            break;
        }
        ans.push_back(segments[p]);
        if (r >= M) {
            break;
        }
        l = r;
    }

    if (r < M) {
        cout << "0\n";
        cout << "\n";
        return;
    }

    cout << ans.size() << "\n";
    for (auto &[x, y] : ans) {
        cout << x << " " << y << "\n";
    }
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