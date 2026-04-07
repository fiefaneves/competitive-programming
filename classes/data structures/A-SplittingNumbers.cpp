#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;

    while (cin >> n && n!=0) {
        ll a = 0;
        ll b = 0;
        bool turn_a = true;

        while (n > 0) {
            ll bit = LSOne(n);
            if (turn_a) {
                a |= bit;
            } else {
                b |= bit;
            }

            n -= bit;
            turn_a = !turn_a;
        }

        cout << a << " " << b << "\n";
    }

    return 0;
}