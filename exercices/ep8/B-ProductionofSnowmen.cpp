#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        ll v1 = 0;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (a[j] >= b[(j+i)%n]) {
                    ok = false;
                    break;
                }
            }
            if (ok) v1++;
        }
        

        ll v2 = 0;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (b[j] >= c[(j+i)%n]) {
                    ok = false;
                    break;
                }
            }
            if (ok) v2++;
        }
        
        ll ans = n * v1 * v2;
        cout << ans << "\n";
    }

    return 0;
}