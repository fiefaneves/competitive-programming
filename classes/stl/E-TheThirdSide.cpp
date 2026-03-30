#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (size_t i = 0; i < t; i++) {
        int n; cin >> n;
        long long sum = 0;
        for (size_t j = 0; j < n; j++) {
            int x; cin >> x;
            sum += x;
        }

        long long ans = sum - (n - 1);
        cout << ans << '\n';
    }    

    return 0;
}