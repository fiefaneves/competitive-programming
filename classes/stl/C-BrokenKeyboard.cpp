#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;
    while (cin >> t) {
        string p1 = "";
        string p2 = "";
        char i = 'x';
        for (char c : t) {
            if (c != '[' && c != ']' && i != '[') p2.push_back(c);
            if (c == ']') i = 'x';
            if (i == '[' && c != '[') p1.push_back(c);
            if (c == '[') i = '[';
        }        
        cout << p1 << p2 << '\n';
    }   

    return 0;
}