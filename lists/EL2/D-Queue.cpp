#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    queue<pair<string,int>> p; 
    for (size_t i = 0; i < n; i++) {
        string x; cin >> x;
        int t; cin >> t;
        p.push({x,t});
    }
    
    int total_time = 0;
    while (!p.empty()) {
        int time_r = p.front().second - q;
        if (time_r == 0) {
            total_time+=q;
            cout << p.front().first << " " << total_time << '\n';
            p.pop();
        } else if (time_r < 0) {
            total_time += p.front().second;
            cout << p.front().first << " " << total_time << '\n';
            p.pop();
        } else { // time_r > 0
            total_time+=q;
            p.push({p.front().first, p.front().second-q});
            p.pop();
        }
    }    

    return 0;
}