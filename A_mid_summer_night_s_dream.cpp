#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 2E5 + 9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    while (cin >> n) {
        vector<int> vec(n);
        for (auto &x : vec) {
            cin >> x;
        }
        
        sort(vec.begin(), vec.end());
        
        int mid = vec[n / 2];
        int k = 0;
        int cnt = 0;
        int diff = 1;

        if (n % 2 == 0) {
            k = vec[n / 2];
            mid = vec[n / 2 - 1];
            diff = k - mid + 1;
        } else {
            k = mid;
        }

        for (auto &x : vec) {
            if (x >= mid && x <= k) {
                cnt++;
            }
        }
        
        cout << mid << " " << cnt << " " << diff << "\n";
    }   
    
    return 0;
}