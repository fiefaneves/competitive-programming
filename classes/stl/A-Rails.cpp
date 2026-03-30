#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n && n != 0) {
        while (true) {
            int first; cin >> first;
            if (first == 0) {
                cout << '\n';
                break;
            }

            vector<int> target(n);
            target[0] = first;
            for (size_t i = 1; i < n; i++) {
                cin >> target[i];
            }

            stack<int> s;
            int incoming = 1;
            int target_idx = 0;   
            
            while (incoming <= n) {
                s.push(incoming);
                incoming++;

                while(!s.empty() && s.top() == target[target_idx]) {
                    s.pop();
                    target_idx++;
                }
            }

            if (s.empty()) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}