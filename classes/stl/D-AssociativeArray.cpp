#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<long long, long long> a;

    int t; cin >> t;
    int op;
    long long k, v;
    for (size_t i = 0; i < t; i++) {
        cin >> op;
        if (op == 0) {
            cin >> k >> v;
            a[k] = v;
        } else if (op == 1) {
            cin >> k;

            auto it = a.find(k);
            if (it != a.end()) {
                cout << it->second << '\n';
            } else {
                cout << 0 << '\n';
            }
        }        
    }
    
    return 0;
}