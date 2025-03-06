#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 1E4 + 9;

struct BigInt {
    string S;

    BigInt() : S("0") {}

    BigInt &operator=(const int &x) {
        S = to_string(x);
        return *this;
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

BigInt f[N];
BigInt two[N];

int check(int x) {
    int sum = 0, prev = 0;
    for (int i = 1; i < N; i++) {
        prev = sum;
        sum += i;
        if (sum >= x && x > prev) {
            return i - 1;
        }
    }
}

// f[0] = 0
// f[1] = 1 + 2^0 = 1
// f[2] = f[1] + 2^1 = 3
// f[3] = f[2] + 2^1 = 5
// f[4] = f[3] + 2^2 = 9
// f[5] = f[4] + 2^2 = 13
// f[6] = f[5] + 2^2 = 17
void init() {
    f[0] = 0;
    two[0] = 1;

    for (int i = 1; i < N; i++) {
        two[i] = two[i - 1] * 2;
    }

    f[1] = f[0] + two[0];
    for (int i = 2; i < N; i++) {
        f[i] = f[i - 1] + two[i];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    init();

    int n;
    while (cin >> n) {
        f[n].print();
    }

    return 0;
}