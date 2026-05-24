#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a, b; cin >> a >> b;
    vector<ll> p;
    ll curr = b;
    p.push_back(curr);

    while (curr > a) {
        if (curr % 10 == 1) curr /= 10;
        else if (curr % 2 == 0) curr /= 2;
        else break;

        p.push_back(curr);
    }

    if (curr == a) {
        cout << "YES\n";
        cout << p.size() << "\n";
        for (int i = p.size()-1; i >= 0; i--) {
            cout << p[i] << " ";
        }
    } else {
        cout << "NO";
    }

    return 0;
}