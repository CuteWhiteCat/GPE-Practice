#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // 考慮 a + b = d - c
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        // 最大化 d，所以 d - c = (a + b) 也要最大
        unordered_map<int, vector<pii>> mp;
        vector<int> vec(n);
        for (auto &x : vec) {
            cin >> x;
        }

        // a + b
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = vec[i] + vec[j];
                mp[sum].push_back(make_pair(i, j));
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int diff = vec[i] - vec[j];
                    if (mp.count(diff)) {
                        for (auto &[x, y] : mp[diff]) {
                            if (i != x && i != y && j != x && j != y) {
                                ans = max(ans, vec[i]);
                            }
                        }
                    }
                }
            }
        }

        if (ans == INT_MIN) {
            cout << "no solution\n";
        } else {
            cout << ans << "\n";
        }
    }

    return 0;
}