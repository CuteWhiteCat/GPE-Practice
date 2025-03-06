#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

void dfs(string s, int k, vector<ll> &vec) {
    int sign = 1;
    int num = 0;
    int n = s.size();
    int i = 1;
    char op;

    for (; i < n; i++) {
        if (s[i] == '-') {
            sign = -1;
        } else if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        } else {
            op = s[i];
            break;
        }
    }

    num *= sign;

    if (op == '+') {
        dfs(s.substr(i + 1), k, vec);
        int prev = vec[0];
        vec[0] = num;
        for (int i = 1; i < k; i++) {
            int tmp = vec[i];
            vec[i] = vec[i - 1] + prev;
            prev = tmp;
        }
    } else if (op == '*') {
        dfs(s.substr(i + 1), k, vec);
        vec[0] *= num;
        for (int i = 1; i < k; i++) {
            vec[i] *= vec[i - 1];
        }
    } else {
        fill(vec.begin(), vec.end(), num);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    int n;
    while (cin >> s >> n) {
        vector<ll> vec(n);
        dfs(s, n, vec);
        for (int i = 0; i < n; i++) {
            cout << vec[i] << " \n"[i == n - 1];
        }
    }

    return 0;
}