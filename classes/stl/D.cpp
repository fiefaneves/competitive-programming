#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        string s1;
        cin >> s1;
        string s2 = "";

        for (int j = s1.size()-1; j >= 0; j--) {
            if (s1[j] == 'q') s2.push_back('p');
            if (s1[j] == 'p') s2.push_back('q'); 
            if (s1[j] == 'w') s2.push_back('w');
        }
        cout << s2 << endl;
    }
    
    return 0;
}