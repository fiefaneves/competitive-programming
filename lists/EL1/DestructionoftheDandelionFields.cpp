#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;        
    long long int a;

    vector<long long int> odds;
    long long int sum = 0;

    for (size_t j = 0; j < n; j++) {
        cin >> a;
        if (a%2 == 0) {
            sum += a;
        } else {
            odds.push_back(a);
        }
    }

    if (odds.empty()) {
        cout << 0 << '\n';
        return;
    }

    sort(odds.rbegin(), odds.rend());
    int half = (odds.size() + 1) / 2;

    for (size_t j = 0; j < half; j++) {
        sum += odds[j];
    }
    
    cout << sum << '\n';  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for (size_t i = 0; i < t; i++) {
       solve();   
    }
    return 0;
}