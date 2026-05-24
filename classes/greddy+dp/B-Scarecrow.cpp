#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    for (size_t j = 1; j <= t; j++) {
        int n; cin >> n;
        vector<char> f(n);
        for (size_t i = 0; i < n; i++) {
            cin >> f[i];
        }

        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            if (f[i] == '.') {
                ans++;
                i+=2;
            }               
        }
        
        cout << "Case " << j << ": " << ans << '\n';        
    }

    return 0;
}