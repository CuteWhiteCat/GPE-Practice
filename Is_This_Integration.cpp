#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

const double PI = acos(-1.0);

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cout << fixed;
    
    double a;
    while (cin >> a) {
        cout << setprecision(3);
        cout << (1 - sqrt(3) + PI / 3) * pow(a, 2) << " ";
        cout << (2 * sqrt(3) - 4 + PI / 3) * pow(a, 2) << " ";
        cout << (4 - sqrt(3) - 2 * PI / 3) * pow(a, 2) << "\n";
    }
    
    return 0;
}