#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    for (size_t i = 0; i < t; i++) {
        int n; cin >> n;
        priority_queue<long long> deck;
        long long total_power = 0;

        for (size_t j = 0; j < n; j++) {
            long long s; cin >> s;
            if (s > 0) {
                deck.push(s);
            } else if (s == 0) {
                if (!deck.empty()) {
                    total_power += deck.top();
                    deck.pop();
                }
            }
        }

        cout << total_power << '\n';
    }
    

    return 0;
}