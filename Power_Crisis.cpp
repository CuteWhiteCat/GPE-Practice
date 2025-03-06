#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    while (cin >> N) {
        if (N == 0) {
            break;
        }
        // 從 1 開始，所以視為 2 ~ n 的Joseph Problem
        // n - 1 個數，所以迴圈 n - 1 次
        // pos = (pos + m) % size
        // 13 會平移到 13 -> 12(少一個) -> 11(從0開始)
        for (int i = 1; i <= N; i++) {
            int pos = 0;
            for (int j = 1; j < N; j++) {
                pos = (pos + i) % j;
            }
            if (pos == 11) {
                cout << i << "\n";  
                break;  
            }
        }
    }
    
    return 0;
}