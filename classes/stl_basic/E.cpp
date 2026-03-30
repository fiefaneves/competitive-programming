#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   
   int t; cin >> t;
   string s1;

   for (size_t i = 0; i < t; i++) {
    string s2 = "";
    for (size_t j = 0; j < 3; j++) {
        cin >> s1;
        s2.push_back(s1[0]);        
    }
    cout << s2 << '\n';    
   }
   
   return 0;
}