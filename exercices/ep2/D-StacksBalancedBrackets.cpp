#include <bits/stdc++.h>

using namespace std;

bool areMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return true;
    if (char1 == '{' && char2 == '}') return true;
    if (char1 == '[' && char2 == ']') return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;

    while(n--) {
        stack<char> s = {};
        string b; cin >> b;
        bool is_balanced = true;

        for (auto c : b) {
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (s.empty() || !areMatchingPair(s.top(), c)) {
                    is_balanced = false;
                    break;
                }
                s.pop();
            }
        }
        
        if (s.empty() && is_balanced) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}