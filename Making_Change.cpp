#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 700;
constexpr int INF = 0x3f3f3f3f;

vector<int> dollar = {5, 10, 20, 50, 100, 200};
vector<int> change(N + 1, 0);

void init() {
    for (int i = 5; i <= N; i++) {
        int now = i;
        for (int j = 5; j >= 0 && now > 0; j--) {
            change[i] += now / dollar[j];
            now %= dollar[j];
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    init();

    string buffer;
    while (getline(cin, buffer)) {
        stringstream ss(buffer);
        vector<int> cnt(6);

        int x, idx = 0;
        while (ss >> x) {
            cnt[idx++] = x;
            if (idx == 6) {
                break;
            }
        }

        int tot = accumulate(cnt.begin(), cnt.end(), 0);
        if (tot == 0) {
            return 0;
        }

        double tmp;
        ss >> tmp;

        int target = (tmp * 100) + 0.5;
        vector<int> f(N + 1, INF);
        f[0] = 0;

        for (int i = 0; i < 6; i++) {
            for (int k = 1; k <= cnt[i]; k++) {
                for (int j = N; j >= dollar[i]; j--) {
                    f[j] = min(f[j], f[j - dollar[i]] + 1);
                }
            }
        }

        int ans = INF;
        for (int i = target; i <= N; i++) {
            ans = min(ans, f[i] + change[i - target]);
        }

        cout << setw(3) << ans << "\n";
    }

    return 0;
}