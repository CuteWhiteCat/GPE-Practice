#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E4 + 9;

struct Node {
    int w, s;
    int idx;

    bool operator < (const Node &oth) const {
        return s > oth.s;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<Node> vec;
    int w, s;
    int line = 1;
    while (cin >> w >> s) {
        vec.push_back({w, s, line});
        line++;
    }

    sort(vec.begin(), vec.end());

    int n = vec.size();
    vector<int> f(n, 1), prev(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vec[j].s != vec[i].s && vec[j].w > vec[i].w) {
                if (f[j] < f[i] + 1) {
                    f[j] = f[i] + 1;
                    prev[j] = i;
                }
            }
        }
    }

    int ans = *max_element(f.begin(), f.end());
    cout << ans << "\n";

    int pos = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (f[i] == ans) {
            pos = i;
            break;
        }
    }

    vector<int> res;
    while (pos != -1) {
        res.push_back(vec[pos].idx);
        pos = prev[pos];
    }

    reverse(res.begin(), res.end());
    for (auto &x : res) {
        cout << x << "\n";
    }

    return 0;
}