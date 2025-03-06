#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

void solve() {
    double tot = 0;

    string buffer;
    while (getline(cin, buffer)) {
        if (buffer.size() == 0) break;
        stringstream ss(buffer);
        double x1, y1;
        double x2, y2;
        ss >> x1 >> y1 >> x2 >> y2;

        tot += hypot(x2 - x1, y2 - y1);
    }

    tot /= 1000;
    double hr = tot * 2 / 20;
    int mm = round(hr * 60);
    
    cout << mm / 60 << ":";
    if (mm % 60 < 10) {
        cout << "0" << mm % 60 << "\n";
    } else {
        cout << mm % 60 << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    bool first = true;

    int T;
    cin >> T;
    cin.ignore();

    string trash;
    getline(cin, trash);

    while (T--) {
        getline(cin, trash);
        if (!first) {
            cout << "\n";
        }
        first = false;
        solve();
    }

    return 0;
}