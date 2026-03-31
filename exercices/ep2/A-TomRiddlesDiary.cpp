#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    set<string> names;
    int last = 0;

    for (size_t i = 0; i < n; i++) {
        string s; cin >> s;
    
        if (names.count(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            names.insert(s);
        }
        
    }

    return 0;
}