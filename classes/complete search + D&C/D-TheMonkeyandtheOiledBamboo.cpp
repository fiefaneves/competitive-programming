#include <bits/stdc++.h>

using namespace std;

// Binary Search on Answer

bool climb(int k, const vector<int>& r) {
    for (size_t i = 0; i < r.size(); i++) {
        int jump = r[i] - r[i-1];
        if (jump > k) {
            return false;
        } else if (jump == k) {
            k--;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    for (int j = 1; j <= t; j++) {
        int n; cin >> n;
        vector<int> r(n+1, 0);
        for (size_t i = 1; i <= n; i++) {
            cin >> r[i];
        }
        
        int L = 1;
        int R = 10000000;
        int ans = R;

        while (L <= R) {
            int mid = L + (R - L) / 2;

            if (climb(mid, r)) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }

        cout << "Case " << j << ": " << ans << "\n";
    }

    return 0;
}