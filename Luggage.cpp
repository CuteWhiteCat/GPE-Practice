#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

void solve() {
    string buffer;
    getline(cin, buffer);

    int n = buffer.size();

    vector<int> vec;

    stringstream ss(buffer);
    int x;
    while (ss >> x) {
        vec.push_back(x);
    }

    int tot = accumulate(vec.begin(), vec.end(), 0);
    if (tot & 1) {
        cout << "NO\n";
        return;
    }

    vector<bool> f(tot + 1, 0);
    f[0] = 1;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = tot; j >= vec[i]; j--) {
            f[j] = f[j - vec[i]];
        }
    }

    cout << (f[tot / 2] ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        solve();
    }

    return 0;
}