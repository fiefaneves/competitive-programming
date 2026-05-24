#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    vector<int> s(n);
    for (size_t i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> dp(n, INF);
    dp[0] = 0;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 1; j <= k; j++) {
            if (i+j < n) {
                int c = dp[i] + abs(s[i] - s[i+j]);
                dp[i+j] = min(dp[i+j], c);
            }
        }  
    }

    cout << dp[n-1] << "\n";    

    return 0;
}