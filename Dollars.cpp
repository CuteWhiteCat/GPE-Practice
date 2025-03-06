#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int cent[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};  // 11

constexpr int N = 3E4 + 9;
ll f[N];

void init() {
    f[0] = 1;
    for (int i = 0; i < 11; i++) {
        for (int j = cent[i]; j <= N; j++) {
            f[j] += f[j - cent[i]];
        }
    }
}

int main() {
    double x;

    init();

    while (scanf("%lf", &x)) {
        if (x == 0.00) {
            break;
        }
        int target = round(x * 100);
        
        printf("%6.2lf%17lld\n", x, f[target]);
    }

    return 0;
}