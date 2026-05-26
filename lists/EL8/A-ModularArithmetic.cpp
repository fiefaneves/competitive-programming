#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

ll fast_pow(ll base, ll exp) {
    ll res = 1;
    base = base % MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll reduce_string(const string& s, ll m) {
    ll res = 0;
    for (char c : s) {
        res = (res * 10 + (c-'0')) % m;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string x, y;
    char op;
    cin >> x >> op >> y;

    ll a = reduce_string(x, MOD);
    ll ans = 0;

    if (op == '+') {
        ll b = reduce_string(y, MOD);
        ans = (a + b) % MOD;
    } else if (op == '-') {
        ll b = reduce_string(y, MOD);
        ans = (((a - b) % MOD) + MOD) % MOD;
    } else if (op == '*') {
        ll b = reduce_string(y, MOD);
        ans = (a * b) % MOD;
    } else {
        ll b = reduce_string(y, MOD-1);
        if (a==0) ans = 0;
        else ans = fast_pow(a, b);
    }
    
    cout << ans;
    return 0;
}