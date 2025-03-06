#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> f(n + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i - 1 >= 0) f[i] += f[i - 1];
        if (i - 2 >= 0) f[i] += f[i - 2];
    }

    cout << f[n] << "\n";
    
    return 0;
}