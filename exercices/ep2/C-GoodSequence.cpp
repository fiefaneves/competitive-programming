#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    map<int,int> f;

    for (size_t i = 0; i < n; i++) { 
        int a; cin >> a;
        f[a]++;
    }

    int rmv = 0;
    for (auto [x,c] : f) {
        if (c > x) {
            rmv += (c-x);
        } else if (c < x) {
            rmv += c;
        }
    }

    cout << rmv << '\n'; 

    return 0;
}