#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E6 + 9;

double ans[N];
double zero[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // 一紅，跟 一紅 & 一白
    // 1 / N * 1 / N + 1 = 1 / N^2 + 1
    
    double p = 0;
    double cnt = 0;
    for (ll i = 1; i < N; i++) {
        p += (1 - p) / (i * (i + 1));
        cnt += log10(i * (i + 1));
        ans[i] = p;
        zero[i] = cnt;
    }

    cout << fixed;
    
    int N;
    while (cin >> N) {
        cout << setprecision(6) << ans[N] << " " << (int)zero[N] << "\n";
    }
    
    return 0;
}