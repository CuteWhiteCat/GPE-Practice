#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string S, T;
    while (getline(cin, S) && getline(cin, T)) {

        map<char, int> cntS;
        map<char, int> cntT;
        for (auto &c : S) {
            cntS[c]++;
        }
        for (auto &c : T) {
            cntT[c]++;
        }

        for (auto &[x, w] : cntS) {
            if (cntT.count(x)) {
                int mn = min(w, cntT[x]);
                for (int i = 1; i <= mn; i++) {
                    cout << x;
                }
            }
        }

        cout << "\n";
    }

    return 0;
}