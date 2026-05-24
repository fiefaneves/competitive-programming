#include <bits/stdc++.h>

using namespace std;

struct Object {
    int p;
    int w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<Object> o(n);
        for (size_t i = 0; i < n; i++) {
            cin >> o[i].p >> o[i].w;
        }
        
        vector<int> m(31,0);

        for (size_t i = 0; i < n; i++) {
            for (size_t w = 30; w >= o[i].w; w--) {
                m[w] = max(m[w], m[w - o[i].w] + o[i].p);
            }
        }
        
        int g; cin >> g;

        long long max = 0;

        for (size_t i = 0; i < g; i++) {
            int mw; cin >> mw;
            max += m[mw];
        }

        cout << max << "\n";    
    }

    return 0;
}