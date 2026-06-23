#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        ans += (p[i].first * p[next].second) - (p[next].first * p[i].second);
    }

    cout << abs(ans) << "\n";

    return 0;
}