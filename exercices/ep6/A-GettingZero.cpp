#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int best = 15;
        for (int j = 0; j <= 15; j++) {
            int v = (x+j) % 32768;
            int mult = 0;

            while (v != 0) {
                v = (v*2) % 32768;
                mult++;
            }

            best = min(best, j+mult);
        }
        cout << best << " ";              
    }
    
    return 0;
}