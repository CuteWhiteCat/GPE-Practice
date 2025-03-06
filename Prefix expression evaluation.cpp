#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string buffer;
    while (getline(cin, buffer)) {
        if (buffer[0] == '.') {
            break;
        }

        int n = buffer.size();
        stack<int> stk;

        bool stop = 0;

        for (int i = n - 1; i >= 0; i--) {
            string num_s = "";
            int val = 0;
            if (isdigit(buffer[i])) {
                while (isdigit(buffer[i])) {
                    num_s += buffer[i--];
                }
                i++;
                reverse(num_s.begin(), num_s.end());
                for (auto &c : num_s) {
                    val = val * 10 + (c - '0');
                }
                stk.push(val);
            } else if (buffer[i] == '+') {
                if (stk.size() < 2) {
                    cout << "illegal\n";
                    stop = 1;
                    break;
                }
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int res = a + b;
                stk.push(res);
            } else if (buffer[i] == '-') {
                if (stk.size() < 2) {
                    cout << "illegal\n";
                    stop = 1;
                    break;
                }
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int res = a - b;
                stk.push(res);
            } else if (buffer[i] == '*') {
                if (stk.size() < 2) {
                    cout << "illegal\n";
                    stop = 1;
                    break;
                }
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int res = a * b;
                stk.push(res);
            } else if (buffer[i] == '/') {
                if (stk.size() < 2) {
                    cout << "illegal\n";
                    stop = 1;
                    break;
                }
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int res = a / b;
                stk.push(res);
            } else if (buffer[i] == '%') {
                if (stk.size() < 2) {
                    cout << "illegal\n";
                    stop = 1;
                    break;
                }
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int res = a % b;
                stk.push(res);
            }
        }

        if (stop == 0 && stk.empty()) {
            cout << "illegal\n";
        } else if (stop == 0) {
            cout << stk.top() << "\n";
        }
    }

    return 0;
}