#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fast_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c; cin >> c;
    
    while(c--) {
        ll x, y, n; cin >> x >> y >> n;
        cout << fast_pow(x, y, n) << "\n";
    }

    return 0;
}