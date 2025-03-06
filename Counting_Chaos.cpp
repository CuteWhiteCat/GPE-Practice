#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

string solve() {
    string s;
    cin >> s;

    string res = "";

    int min = (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
    while (true) {
        min++;
        if (min >= 1440) {
            min = 0;
        }

        int HH = min / 60;
        int MM = min % 60;
        if (HH == 0) {
            if (MM < 10 || (MM / 10 == MM % 10)) {
                res += "00:";
                if (MM < 10) {
                    res += "0";
                }
                res += to_string(MM);
                break;
            }
        } else if (HH < 10) {
            if (HH == MM % 10) {
                res += "0";
                res += to_string(HH);
                res += ":";
                if (MM < 10) {
                    res += "0";
                }
                res += to_string(MM);
                break;
            }
        } else {
            string H = to_string(HH);

            string M = to_string(MM);
            if (MM < 10) {
                M.insert(M.begin(), '0');
            }
            reverse(H.begin(), H.end());
            if (H == M) {
                res += to_string(HH);
                res += ":";
                if (MM < 10) {
                    res += "0";
                }
                res += to_string(MM);
                break;
            }
        }
    }

    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        cout << solve() << "\n";
    }

    return 0;
}