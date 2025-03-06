#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

// 媽的Sample Input沒有空格隔開阿
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    string S, T;
    while (getline(cin, S)) {
        getline(cin, T);
        int n = S.size();
        int m = T.size();
        
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++) {
            f[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            f[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (S[i - 1] == T[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }

        cout << f[n][m] << "\n";
    }
    
    return 0;
}