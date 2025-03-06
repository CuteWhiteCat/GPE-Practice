#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string buffer;
        getline(cin, buffer);

        stringstream ss(buffer);
        char op;
        int x;
        ss >> x;

        vector<ll> MI{x};
        vector<ll> MA{x};

        while (ss >> op >> x) {
            int n = MI.size() - 1;
            int m = MA.size() - 1;
            if (op == '+') {
                MI.push_back(x);
                MA[m] += x;
            } else {
                MA.push_back(x);
                MI[n] *= x;
            }
        }

        ll mn = 0, mx = 1;
        for (auto &i : MI) {
            mn += i;
        }
        for (auto &i : MA) {
            mx *= i;
        }

        cout << "The maximum and minimum are " << mx << " and " << mn << ".\n";
    }
    
    return 0;
}