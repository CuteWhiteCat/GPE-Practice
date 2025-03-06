#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 65540;

int top;
int stk[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto &x : vec) {
        cin >> x;
    }

    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(stk + 1, stk + 1 + top, vec[i]) - stk;
        if (pos == top + 1) {
            ++top;
        }
        stk[pos] = vec[i];
    }

    cout << top << "\n";
    
    return 0;
}