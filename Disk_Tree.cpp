#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E4 + 9;
int tot = 0;

struct Node {
    string dir;
    map<string, int> to;
} t[N];

int newNode() {
    tot++;
    t[tot].dir = "";
    t[tot].to.clear();
    return tot;
}

void insert(string &s) {
    vector<string> dirs;
    stringstream ss(s);
    string buffer;
    while (getline(ss, buffer, '\\')) {
        dirs.push_back(buffer);
    }

    int p = 1;
    for (auto &d : dirs) {
        if (t[p].to.find(d) == t[p].to.end()) {
            int next = newNode();
            t[next].dir = d;
            t[p].to[d] = next;
        }
        p = t[p].to[d];
    }
}

void print(int p, int dep) {
    for (auto &[dir, ch] : t[p].to) {
        for (int i = 0; i < dep; i++) {
            cout << " ";
        }
        cout << dir << "\n";
        print(ch, dep + 1);
    }
}

// 這是甚麼鳥題目
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    while (cin >> n) {
        tot = 0;
        
        newNode();
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            insert(s);
        }

        print(1, 0);
        cout << "\n";
    }

    return 0;
}