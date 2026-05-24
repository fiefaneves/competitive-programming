#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int max = 7489;

    vector<ll> dp(max+1, 0);
    dp[0] = 1;

    vector<int> coins = {1, 5, 10, 25, 50};

    for (auto c : coins) {
        for (int i = c; i <= max; i++) {
            dp[i] += dp[i-c];
        }        
    }

    int n;

    while (cin >> n) {
        cout << dp[n] << "\n";
    }
    
    return 0;
}