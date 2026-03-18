#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s1; cin >> s1;
    string ans = "";

    for (char c : s1) {
        ans.push_back(c);
        int n = ans.size();

        if (n >= 3 && ans[n-3] == 'A' && ans[n-2] == 'B' && ans[n-1] == 'C') {
            ans.pop_back(); 
            ans.pop_back(); 
            ans.pop_back(); 
        }
    }
    cout << ans << '\n';

    return 0;
}