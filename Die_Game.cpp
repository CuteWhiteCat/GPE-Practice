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
        if (n == 0) {
            break;
        }
        int top = 1;
        int north = 2;
        int west = 3;

        while (n--) {
            string s;
            cin >> s;
            if (s == "north") {
                int tmp = north;
                north = top;
                top = 7 - tmp;
            }
            if (s == "south") {
                int tmp = top;
                top = north;
                north = 7 - tmp;
            }
            if (s == "west") {
                int tmp = west;
                west = top;
                top = 7 - tmp;
            }
            if (s == "east") {
                int tmp = top;
                top = west;
                west = 7 - tmp;
            }
        }
        cout << top << "\n";
    }

    return 0;
}