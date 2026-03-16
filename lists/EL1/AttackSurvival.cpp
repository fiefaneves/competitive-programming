#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;
    int p;
    vector<int> pts(n, k);

    for (size_t i = 0; i < q; i++) {
        cin >> p;
        for (size_t j = 0; j < n; j++) {
            if (j != p-1) pts[j]--;
        }
    }
    
    for (int pt : pts) {
        if (pt<=0) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
        }
    }

    return 0;
}