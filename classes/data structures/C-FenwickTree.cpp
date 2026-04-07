#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

typedef long long ll;

class FenwickTree {
private:
    vector<ll> ft;

public:
    FenwickTree(int m) {ft.assign(m+1,0);}

    ll rsq(int j) {
        ll sum = 0;
        for (; j > 0; j -= LSOne(j)) {
            sum += ft[j];
        }
        return sum;        
    }

    void update(int i, ll v) {
        for (; i < (int)ft.size(); i += LSOne(i)) {
            ft[i] += v;
        }        
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q; cin >> n >> q;
    FenwickTree ft(n);
    for (size_t i = 0; i < q; i++) {
        char op; cin >> op;
        if (op == '?') {
            int e; cin >> e;
            cout << ft.rsq(e) << '\n';            
        } else if (op == '+') {
            int e;
            ll v;
            cin >> e >> v;
            ft.update(e+1, v);
        }
    }
    return 0;
}