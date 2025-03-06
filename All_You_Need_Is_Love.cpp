#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int bin(const string &s) {
    int res = 0;
    for (auto &c : s) {
        int x = c - '0';
        res = res * 2 + x;
    }
    return res;
}

void solve() {
    string S, T;
    cin >> S >> T;
    int a = bin(S);
    int b = bin(T);
    int g = __gcd(a, b);
    if (g != 1) {
        cout << "All you need is love!\n";
    } else {
        cout << "Love is not all you need!\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Pair #" << i << ": ";
        solve();
    }
    
    return 0;
}