#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    ll tw = 0;
    ll th = 0;
    vector<pair<ll, ll>> it;

    for (size_t i = 0; i < n; i++) {
        ll  w, h, b;
        cin >> w >> h >> b;

        tw += w;
        th += b;

        if (h > b) it.push_back({w, h-b});
    }

    int c = tw/2;
    vector<ll> dp(c+1, 0);

    for (auto i : it) {
        int w = i.first;
        ll v = i.second;

        for (size_t j = c; j >= w; j--) {
            dp[j] = max(dp[j], dp[j-w]+v);
        }
    }   
    cout << th + dp[c] << "\n";

    return 0;
}