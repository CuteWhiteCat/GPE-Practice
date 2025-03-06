#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int phi(int x) {
    int res = x;

    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            res /= i;
            res *= (i - 1);
            while (x % i == 0) {
                x /= i;
            }
        }
    }

    if (x > 1) {
        res /= x;
        res *= (x - 1);
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

        cout << phi(n) << "\n";
    }

    return 0;
}