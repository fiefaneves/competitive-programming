#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a, b; cin >> n >> a >> b;
    int max = 6*n;
    vector<double> dp(max+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        vector<double> next_dp(max+1, 0);
        for (int j = 1; j <= 6*i; j++) {
            for (int f = 1; f <= 6; f++) {
                if (j-f >= 0) next_dp[j] += dp[j-f] / 6;
            }
        }
        dp = next_dp;
    }

    double ans = 0;
    for (int i = a; i <= b; i++) {
        ans += dp[i];
    }
    cout << fixed << setprecision(6) << ans;

    return 0;
}