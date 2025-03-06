#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(2);

    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        vector<int> vec(n);
        for (auto &x : vec) {
            double tmp;
            cin >> tmp;
            x = round(tmp * 100);
        }

        sort(vec.begin(), vec.end());

        int tot = accumulate(vec.begin(), vec.end(), 0.0);
        int avg = tot / n;
        int remain = tot % n;

        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            int mid = 0;
            if (i >= n - remain) {
                mid = avg + 1;
            } else {
                mid = avg;
            }

            if (vec[i] > mid) {
                ans += vec[i] - mid;
            }
        }

        cout << "$" << ans / 100.0 << "\n";
    }

    return 0;
}