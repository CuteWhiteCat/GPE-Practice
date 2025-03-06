#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

bool cmp(const vector<ll> &A, const vector<ll> &B) {
    return A.size() != B.size() ? A.size() < B.size() : A < B;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<ll> vec;

    string buffer;
    while (getline(cin, buffer)) {
        if (buffer[0] == '.') {
            break;
        }

        vec.clear();
        buffer.erase(buffer.begin());
        buffer.erase(buffer.end() - 1);

        stringstream ss(buffer);
        ll x;
        while (ss >> x) {
            vec.push_back(x);
        }

        int n = vec.size();
        ll tot = accumulate(vec.begin(), vec.end(), 0LL);

        if (tot & 1) {
            cout << "No such subset\n";
            continue;
        }

        vector<vector<ll>> ans;

        for (int i = 0; i < (1 << n); i++) {
            vector<ll> cur;
            ll sum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1LL << j)) {
                    sum += vec[j];
                    cur.push_back(vec[j]);
                }
            }

            if (sum == tot / 2) {
                ans.push_back(cur);
            }
        }

        sort(ans.begin(), ans.end(), cmp);

        if (ans.size() == 0) {
            cout << "No such subset\n";
            continue;
        }

        cout << ans.size() << " subsets.\n";
        for (auto &v : ans) {
            cout << "{";
            int m = v.size();
            for (int i = 0; i < m; i++) {
                cout << v[i];
                if (i != m - 1) cout << " ";
            }
            cout << "}\n";
        }
        cout << "\n";
    }

    return 0;
}