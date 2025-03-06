#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    bool first = true;
    while (cin >> n) {
        cin.ignore();
        map<string, int> cnt;

        string buffer;
        bool stop = false;
        while (getline(cin, buffer)) {
            string s = "";
            int m = buffer.size();

            for (int i = 0; i < m; i++) {
                if (isalpha(buffer[i])) {
                    s += tolower(buffer[i]);
                } else {
                    if (!s.empty()) {
                        cnt[s]++;
                        s = "";
                    }
                }
            }

            if (!s.empty()) {
                if (s == "endoftext") {
                    break;
                } else {
                    cnt[s]++;
                }
            }
        }

        if (!first) {
            cout << "\n";
        }
        first = false;

        vector<string> res;
        for (auto &[s, c] : cnt) {
            if (c == n) {
                res.push_back(s);
            }
        }

        if (!res.empty()) {
            for (auto &s : res) {
                cout << s << "\n";
            }
        } else {
            cout << "There is no such word.\n";
        }
    }

    return 0;
}