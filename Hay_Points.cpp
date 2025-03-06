#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    map<string, int> words;
    for (int i = 0; i < n; i++) {
        string s;
        int val;
        cin >> s >> val;
        words[s] = val;
    }

    for (int i = 0; i < m; i++) {
        string buffer;
        int ans = 0;
        while (cin >> buffer) {
            if (buffer == ".") {
                break;
            }
            ans += words[buffer];
        }

        cout << ans << "\n";
    }
    
    return 0;
}