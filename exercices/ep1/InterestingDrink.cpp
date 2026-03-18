#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    int x;
    vector<int> bars(n); 

    for (size_t i = 0; i < n; i++) {
        cin >> x;
        bars[i] = x; 
    }
    sort(bars.begin(), bars.end());

    int q; cin >> q;
    int m;
    for (size_t i = 0; i < q; i++) {
        cin >> m;
        
        auto s = upper_bound(bars.begin(), bars.end(), m);
        int sum = distance(bars.begin(), s);

        cout << sum << '\n';
    }

    return 0;
}