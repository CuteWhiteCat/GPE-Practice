#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

string manacher(string s) {
    string t = "#";
    for (auto c : s) {
        t += c;
        t += "#";
    }
    int n = t.size();
    vector<int> d(n);
    d[0] = 1;
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) d[i] = min(d[r - i + l], r - i + 1);
        while (i - d[i] >= 0 && i + d[i] < n && t[i - d[i]] == t[i + d[i]]) {
            ++d[i];
        }
        if (i + d[i] - 1 > r) {
            l = i - d[i] + 1;
            r = i + d[i] - 1;
        }
    }

    int mx = 0;
    int pos = 0;

    for (int i = 0; i < n; i++) {
        if (d[i] > mx && i + d[i] == n) {
            mx = d[i];
            pos = i;
        }
    }

    string add = "";
    for (int i = 0; i < pos - mx + 1; i++) {
        if (t[i] != '#') {
            add += t[i];
        }
    }
    reverse(add.begin(), add.end());
    
    return s + add;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    while (cin >> s) {
        cout << manacher(s) << "\n";
    }

    return 0;
}