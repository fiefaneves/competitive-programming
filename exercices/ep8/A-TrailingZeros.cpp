#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    ll ans = 0;
    while (n>=5) {
        n /= 5;
        ans+=n;
    }
    cout << ans;
    return 0;
}