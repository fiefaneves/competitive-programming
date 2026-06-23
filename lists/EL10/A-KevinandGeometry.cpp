#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        
        vector<int> pairs; 
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                pairs.push_back(a[i]);
                i++; 
            }
        }

        bool found = false;

        if (pairs.size() >= 2) {
            int p1 = pairs.back();
            pairs.pop_back();
            int p2 = pairs.back();
            cout << p1 << " " << p1 << " " << p2 << " " << p2 << "\n";
            found = true;
        } 
        else if (pairs.size() == 1) {
            int L = pairs[0];
            vector<int> rem;
            int countL = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == L && countL < 2) countL++;
                else rem.push_back(a[i]);
            }

            for (int i = 0; i < rem.size() - 1; i++) {
                if (rem[i+1] - rem[i] < 2LL * L) {
                    cout << L << " " << L << " " << rem[i] << " " << rem[i+1] << "\n";
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << "-1\n";
        }
    }

    return 0;
}