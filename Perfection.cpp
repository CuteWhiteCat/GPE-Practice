#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cout << "PERFECTION OUTPUT\n";
    
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        ll sum = 0;
        // 只會在 1 ~ n / 2 才有可能
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }
        cout << setw(5) << n << "  ";
        if (sum == n) {
            cout << "PERFECT\n";
        } else if (sum >= n) {
            cout << "ABUNDANT\n";
        } else {
            cout << "DEFICIENT\n";
        }
    }   

    cout << "END OF OUTPUT\n";
    
    return 0;
}