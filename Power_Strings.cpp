#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E6 + 9;
constexpr int P = 131;

ull p[N];

void init() {
    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = p[i - 1] * P;
    }
}

bool match(int r, int n, vector<ull> &hash) {
    int len = r + 1;
    ull base = hash[r];
    for (int i = len; i < n; i += len) {
        ull cur = hash[i + len - 1];
        if (i > 0) {
            cur -= hash[i - 1] * p[len];
        }
        if (cur != base) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    init();

    string s;
    while (cin >> s) {
        if (s[0] == '.') {
            break;
        }

        int n = s.size();
        vector<ull> hash(n);
        hash[0] = s[0];
        for (int i = 1; i < n; i++) {
            hash[i] = hash[i - 1] * P + (ull)(s[i]);
        }

        bool found = false;

        for (int i = 0; i < n; i++) {
            if (n % (i + 1) != 0) continue;

            if (match(i, n, hash)) {
                cout << n / (i + 1) << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "1\n";
        }
    }

    return 0;
}