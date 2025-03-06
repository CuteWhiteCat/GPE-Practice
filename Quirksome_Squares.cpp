#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    while (cin >> n) {
        int k = pow(10, n / 2);
        for (int i = 0; i < k; i++) {
            if ((i * i % k) + (i * i / k) == i) {
                int tmp = i * i;
                int cnt = 0;
                if (tmp == 0) {
                    cnt = 1;
                } else {
                    while (tmp) {
                        cnt++;
                        tmp /= 10;
                    }
                }
                for (int j = n; j > cnt; j--) {
                    cout << 0;
                }
                cout << i * i << "\n";
            }
        }
    }

    return 0;
}