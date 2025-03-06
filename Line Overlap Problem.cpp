#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

#define f first
#define s second

bool cmp(const pii &A, const pii &B) {
    return A.f != B.f ? A.f < B.f : A.s < B.s;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<pii> segments;
    
    string buffer;
    while (getline(cin, buffer)) {
        if (buffer[0] == '.') {
            break;
        }

        stringstream ss(buffer);
        ll L, R;
        ss >> L >> R;
        
        segments.push_back({L, 1});
        segments.push_back({R, -1});
    }

    sort(segments.begin(), segments.end(), cmp);

    ll cnt = 0, prev = 0, ans = 0;
    for (auto &[x, k] : segments) {
        if (x > prev && cnt >= 2) {
            ans += (x - prev) * (cnt * (cnt - 1) / 2); // overlap len * 取兩個
        }
        cnt += k;
        prev = x;
    }

    cout << ans << "\n";
    
    return 0;
}