#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        bool is_sorted = true;
        int prev = -1;
        
        for (size_t i = 0; i < n; i++) {
            int curr; cin >> curr;

            if (curr < prev) {
                is_sorted = false;
            }
            prev = curr;
        }

        if (is_sorted) {
            cout << n << "\n";
        } else {
            cout << 1 << "\n";
        }
    }

    return 0;
}