#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

bool cmp(const string &A, const string &B) {
    return A + B > B + A;
}

// 這題考慮拼起來拿來排序
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        vector<string> vec(n);
        for (auto &s : vec) {
            cin >> s;
        }

        sort(vec.begin(), vec.end(), cmp);

        for (auto &s : vec) {
            cout << s;
        }

        cout << "\n";
    }
    
    return 0;
}