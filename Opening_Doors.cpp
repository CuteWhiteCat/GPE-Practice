// 一眼大數開根號取整，愛寫誰寫
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

struct BigInt {
    string S;

    BigInt() : S("0") {}
    BigInt(string s) {
        S = s;
    }

    BigInt &operator=(const int &x) {
        S = to_string(x);
        return *this;
    }

    bool operator==(const BigInt &oth) const {
        return S == oth.S;
    }

    int cmp(const BigInt &oth) const {
        if (S.size() < oth.S.size()) return -1;
        if (S.size() > oth.S.size()) return 1;
        if (S < oth.S) return -1;
        if (S > oth.S) return 1;
        return 0;
    }

    void print() const {
        cout << S << "\n";
    }

    BigInt operator+(const BigInt &oth) const {
        string A = S;
        string B = oth.S;
        if (A.size() < B.size()) {
            swap(A, B);
        }

        int carry = 0;
        int n = A.size();
        int m = B.size();
        string K = A;

        for (int i = 1; i <= m; i++) {
            int tmp = (A[n - i] - '0') + (B[m - i] - '0') + carry;
            K[n - i] = (tmp % 10) + '0';
            carry = tmp / 10;
        }

        for (int i = m + 1; i <= n; i++) {
            int tmp = (A[n - i] - '0') + carry;
            K[n - i] = (tmp % 10) + '0';
            carry = tmp / 10;
        }

        while (carry) {
            K.insert(K.begin(), (carry % 10) + '0');
            carry /= 10;
        }

        BigInt res;
        res.S = K;
        return res;
    }

    BigInt operator*(const int &x) const {
        int carry = 0;
        int n = S.size();
        string K = S;

        for (int i = n - 1; i >= 0; i--) {
            int tmp = (S[i] - '0') * x + carry;
            K[i] = (tmp % 10) + '0';
            carry = tmp / 10;
        }

        while (carry) {
            K.insert(K.begin(), (carry % 10) + '0');
            carry /= 10;
        }

        BigInt res;
        res.S = K;
        return res;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string n;
    while (cin >> n) {
        if (n == "0") {
            break;
        }

        BigInt ans = BigInt(n);
        ans.print();
    }

    return 0;
}