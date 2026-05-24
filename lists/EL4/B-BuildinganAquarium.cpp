#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool build(ll h, const vector<ll>& a, ll x) {
    ll water_used = 0;

    for (size_t i = 0; i < a.size(); i++) {
        if (h > a[i]) {
            water_used += (h - a[i]);
        }
    }

    return water_used <= x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        ll n, x; cin >> n >> x;
        
        vector<ll> a(n);
        for (size_t i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll L = 1;
        ll R = 2000000000LL;
        ll ans = 1;

        while (L <= R) {
            ll mid = L + (R - L) / 2;

            if(build(mid, a, x)){
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        
        cout << ans << "\n";
    }

    return 0;
}