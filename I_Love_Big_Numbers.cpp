#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

string mul(string s, int x) {
    int carry = 0;
    int n = s.size();
    
    for (int i = n - 1; i >= 0; i--) {
        int tmp = (s[i] - '0') * x + carry;
        s[i] = (tmp % 10) + '0';
        carry = tmp / 10;
    }

    while (carry) {
        s.insert(s.begin(), carry % 10 + '0');
        carry /= 10;
    }
    
    return s;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    while (cin >> n) {
        string s = "1";
        for (int i = 2; i <= n; i++) {
            s = mul(s, i);
        }
        
        int ans = 0;    
        for (auto &c : s) {
            ans += (c - '0');
        }
        cout << ans << "\n";
    }
    
    return 0;
}