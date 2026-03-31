#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    queue<pair<int,int>> line; 

    for (size_t i = 1; i <= n; i++) {
        int a; cin >> a;
        line.push({i,a});
    }
    
    int c;
    while (!line.empty()) {
        c = line.front().second - m;
        if (c <= 0) {
            if (line.size() == 1) {
                cout << line.front().first;
            }            
            line.pop();
        } else {
            line.push({line.front().first, c});
            line.pop();
        }
        
    }    
    
    return 0;
}