#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool valid (ll max_sum, int k, const vector<ll>& v) {
    int sub_a = 1;
    ll curr_sum = 0;

    for (size_t i = 0; i < v.size(); i++) {
        if (curr_sum + v[i] > max_sum) {
            curr_sum = v[i];
            sub_a++;

            if (sub_a > k) {
                return false;
            }
        } else {
            curr_sum += v[i];
        }
    }
    return true;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    vector<ll> x(n);
    ll max_e = 0;
    ll sum = 0;

    for (size_t i = 0; i < n; i++) {
        cin >> x[i];
        max_e = max(max_e, x[i]);
        sum += x[i];
    }

    ll L = max_e;
    ll R = sum;
    ll ans = R;

    while (L <= R) {
        ll mid = L + (R - L) / 2;
        if (valid(mid, k, x)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}