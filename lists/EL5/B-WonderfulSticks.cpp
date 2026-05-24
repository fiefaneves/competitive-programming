#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> ans(n);
        int L = 1;
        int R = n;

        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '<') {
                ans[i+1] = L++;
            } else {
                ans[i+1] = R--;
            }
        }

        ans[0] = L;

        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}