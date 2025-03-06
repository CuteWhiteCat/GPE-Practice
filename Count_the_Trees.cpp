#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 325;

string mul(string s, int x) {
    string res = s;
    int carry = 0;
    
    int n = res.size();
    for (int i = n - 1; i >= 0; i--) {
        int tmp = (res[i] - '0') * x + carry;
        res[i] = (tmp % 10) + '0';
        carry = tmp / 10;
    }

    while (carry) {
        res.insert(res.begin(), (carry % 10) + '0');
        carry /= 10;
    }

    return res;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }   
        
        // fac[2n] / fac[n] * (n + 1)
        // (n + 2) * (n + 3) * ... * (2n)
        string ans = "1";
        for (int i = n + 2; i <= 2 * n; i++) {
            ans = mul(ans, i);
        }

        cout << ans << "\n";
    }
    
    return 0;
}