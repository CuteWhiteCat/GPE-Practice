#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 101;
int pre[N];

int qmi(int a, int b) {
    int res = 1;
    a %= 10;
    while (b) {
        if (b & 1) {
            res = (res * a) % 10;
        }
        a = (a * a) % 10;
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // init
    for (int i = 1; i <= 100; i++) {
        pre[i] = (pre[i - 1] + qmi(i, i)) % 10;
    }

    string s;
    while (cin >> s) {
        if (s == "0") {
            break;
        }
        
        int n = s.size();
        int pos = 0;
        for (int i = max(0, (n - 2)); i < n; i++) {
            pos = pos * 10 + (s[i] - '0');
        }   
        pos %= 100;

        cout << pre[pos] << "\n";
    }

    return 0;
}