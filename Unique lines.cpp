#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

struct P {
    int x, y;
    void read() {
        cin >> x >> y;
    }
    P operator+(const P &b) const {
        return P{x + b.x, y + b.y};
    }
    P operator-(const P &b) const {
        return P{x - b.x, y - b.y};
    }
    void operator+=(const P &b) {
        x += b.x;
        y += b.y;
    }
    void operator-=(const P &b) {
        x -= b.x;
        y -= b.y;
    }
    ll operator*(const P &b) const {
        return (ll)x * b.y - (ll)y * b.x;
    }
    ll cross(const P &b, const P &c) const {
        return (b - *this) * (c - *this);
    }
};

tuple<int, int, int> normalize(int A, int B, int C) {
    int g = __gcd(__gcd(A, B), C);
    if (g == 0) {
        g == 1;
    }
    A /= g;
    B /= g;
    C /= g;

    if (A < 0 || (A == 0 && B < 0)) {
        A = -A;
        B = -B;
        C = -C;
    }

    return make_tuple(A, B, C);
}

void solve() {
    int n;
    cin >> n;

    vector<P> p(n);
    for (int i = 0; i < n; i++) {
        p[i].read();
    }

    set<tuple<int, int, int>> lines;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int A = p[j].y - p[i].y;
            int B = p[j].x - p[i].x;
            int C = p[j] * p[i];
            auto line = normalize(A, B, C);
            lines.insert(line);
        }
    }

    cout << lines.size() << "\n";
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