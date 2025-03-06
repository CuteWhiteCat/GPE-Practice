#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 51;

vector<ll> fibonacci(N);

void init() {
    fibonacci[0] = fibonacci[1] = 1;
    for (int i = 2; i < N; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    init();

    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        } 
        cout << fibonacci[n] << "\n";
    }
    
    return 0;
}