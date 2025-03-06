#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<string> words;

    string buffer;
    while (getline(cin, buffer)) {
        if (buffer == "0") {
            break;
        }
        int n = buffer.size();
        int val = 0;
        string tmp = "";
        for (int i = 0; i < n; i++) {
            if (isdigit(buffer[i])) {
                while (isdigit(buffer[i])) {
                    val = val * 10 + (buffer[i] - '0');
                    i++;
                }
                i--;
                int x = words.size();
                string res = words[x - val];
                cout << res;
                words.erase(words.end() - val);
                val = 0;
                words.push_back(res);
            } else if (isalpha(buffer[i])) {
                while (isalpha(buffer[i])) {
                    tmp += buffer[i];
                    i++;
                }
                i--;
                words.push_back(tmp);
                cout << tmp;
                tmp = "";
            } else {
                cout << buffer[i];
            }
        }
        cout << "\n";
    }

    return 0;
}