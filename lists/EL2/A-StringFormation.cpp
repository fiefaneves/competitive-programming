#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; cin >> s;
    int q; cin >> q;

    deque<char> dq(s.begin(), s.end());
    bool is_reversed = false;

    for (size_t i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            is_reversed = !is_reversed;
        } else if (t == 2) {
            int f; cin >> f;
            char c; cin >> c;
            if (f == 1) {
                if (!is_reversed) {
                    dq.push_front(c);
                } else {
                    dq.push_back(c);
                }
            } else if (f == 2) {
                if (is_reversed) {
                    dq.push_front(c);
                } else {
                    dq.push_back(c);
                }
            }
        }   
    }
    
    if (!is_reversed) {
        for (char c : dq) {
            cout << c;
        }     
    } else {
        for (auto it = dq.rbegin(); it != dq.rend(); it++) {
            cout << *it;
        }
    }

    return 0;
}