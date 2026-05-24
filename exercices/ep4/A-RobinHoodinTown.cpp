#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        ll sum = 0;
        vector<ll> a(n);
        for (size_t i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if (n <= 2) {
            cout << -1 << "\n";
            continue;
        }

        sort(a.begin(), a.end());

        int target = n/2;
        ll w = a[target];
        ll x = (2 * n * w) - sum + 1;

        cout << max(0LL, x) << "\n";
    }

    return 0;
}