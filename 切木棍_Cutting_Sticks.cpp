#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int dfs(int l, int r, vector<vector<int>> &f, vector<int> &vec) {
    if (r - l <= 1) {
        return f[l][r] = 0;
    }
    if (f[l][r] != -1) {
        return f[l][r];
    }

    int res = 1E9;
    for (int i = l + 1; i <= r - 1; i++) {
        res = min(res, dfs(l, i, f, vec) + dfs(i, r, f, vec) + vec[r] - vec[l]);
    }
    return f[l][r] = res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int l;
    while (cin >> l) {
        if (l == 0) {
            break;
        }

        int n;
        cin >> n;

        vector<int> vec(n + 2);
        vec[0] = 0;
        vec[n + 1] = l;
        for (int i = 1; i <= n; i++) {
            cin >> vec[i];
        }

        vector<vector<int>> f(n + 2, vector<int>(n + 2, -1));

        cout << "The minimum cutting is " << dfs(0, n + 1, f, vec) << ".\n";
    }

    return 0;
}