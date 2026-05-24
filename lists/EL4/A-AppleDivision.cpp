#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(int idx, ll s1, ll s2, const vector<ll>& a) {
    if (idx == a.size()) return abs(s1 - s2);

    ll dif1 = solve(idx+1, s1+a[idx], s2, a);

    ll dif2 = solve(idx+1, s1, s2+a[idx], a);

    return min(dif1, dif2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<ll> a(n);
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solve(0, 0, 0, a) << "\n";    

    return 0;
}