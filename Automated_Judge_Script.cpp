#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        cin.ignore();
        vector<string> ans(n);
        for (auto &s : ans) {
            getline(cin, s);
        }

        int m;
        cin >> m;
        cin.ignore();
        vector<string> input(m);
        for (auto &s : input) {
            getline(cin, s);
        }

        cout << "Run #" << ++t << ": ";
        if (ans == input) {
            cout << "Accepted\n";
            continue;
        }

        vector<char> ansNum, inputNum;
        for (auto &s : ans) {
            for (auto &x : s) {
                if (isdigit(x)) {
                    ansNum.push_back(x);
                }
            }
        }
        for (auto &s : input) {
            for (auto &x : s) {
                if (isdigit(x)) {
                    inputNum.push_back(x);
                }
            }
        }

        if (ansNum == inputNum) {
            cout << "Presentation Error\n";
        } else {
            cout << "Wrong Answer\n";
        }
    }

    return 0;
}