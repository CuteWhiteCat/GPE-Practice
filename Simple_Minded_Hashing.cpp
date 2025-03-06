#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 27;
constexpr int M = 352;

int f[N][N][M];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // f[i][j][k] = f[i - 1][j][k] + f[i - 1][j - 1][k - i]
    f[0][0][0] = 1;
    for (int i = 1; i <= 26; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= 351; k++) {
                f[i][j][k] += f[i - 1][j][k];
                if (j > 0 && k >= i) {
                    f[i][j][k] += f[i - 1][j - 1][k - i];
                }
            }
        }
    }

    int L, S;
    int t = 0;
    while (cin >> L >> S) {
        if (L == 0 && S == 0) {
            break;
        }
        cout << "Case " << ++t << ": ";
        cout << (L <= 26 && S <= 351 ? f[26][L][S] : 0) << "\n";
    }
    
    return 0;
}