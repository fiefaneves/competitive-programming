#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> pref(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        pref[i] = pref[i-1] ^ x;
    }

    int max = 0;
    int mask = 0;
    for (int i = 29; i >= 0; i--) {
        mask |= (1 << i);
        int target = max | (1 << i);
        vector<int> v(n+1);
        for (int j = 0; j <= n; j++) {
            v[j] = pref[j] & mask;
        }
        sort(v.begin(), v.end());
        bool found = false;
        for (int x : v) {
            if (binary_search(v.begin(), v.end(), x ^ target)) {
                found = true;
                break;
            }
        }
        if (found) {
            max = target;
        }
    }
    cout << max << "\n";
    return 0;
}