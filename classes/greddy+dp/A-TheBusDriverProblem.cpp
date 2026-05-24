#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, d, r;
    
    while ((cin >> n >> d >> r) && n!=0 && d!=0 && r!=0) {
        vector<int> m(n);
        vector<int> e(n);

        for (size_t i = 0; i < n; i++) cin >> m[i];
        for (size_t i = 0; i < n; i++) cin >> e[i];

        sort(m.begin(), m.end());
        sort(e.begin(), e.end(), greater<int>());
        
        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            int p = m[i] + e[i];
            if (p > d) {
                ans += (p - d)*r;
            }
        }
        cout << ans << '\n';        
    }

    return 0;
}