#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E6 + 9;

int n;
int f[N];

void init() {
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
}

int find(int x) {
    return f[x] = (f[x] == x ? x : find(f[x]));
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    
    if (fx == fy) return;
    f[fx] = fy;
}

bool match(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    return fx == fy;
}

void solve() {
    cin >> n;
    cin.ignore();

    init();

    int suc = 0;
    int unsuc = 0;
    string buffer;
    while (getline(cin, buffer)) {
        if (buffer.size() == 0) {
            break;
        }

        stringstream ss(buffer);
        char op;
        int u, v;
        ss >> op >> u >> v;

        if (op == 'c') {
            merge(u, v);
        } else {
            if (match(u, v)) {
                suc++;
            } else {
                unsuc++;
            }
        }
    }

    cout << suc << "," << unsuc << "\n";
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
        if (!first) {
            cout << "\n";
        }
        first = false;
        solve();
    }

    return 0;
}