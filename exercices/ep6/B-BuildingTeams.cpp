#include <bits/stdc++.h>

using namespace std;

bool bfs(int s, const vector<vector<int>>& adj, vector<int>& c) {
    queue<int> q;
    c[s] = 0;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (c[v] == -1) {
                // Coloca o vizinho no time INVERSO do nó atual
                // Se u é 0, v vira 1. Se u é 1, v vira 0.
                c[v] = 1 - c[u];
                q.push(v);
            } else if (c[v] == c[u]) {
                return false;
            }        
        }
    }
    return true;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> g(n+1);
    vector<int> t(n+1,-1);

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool p = true;
    for (int i = 1; i <= n; i++) {
        if (t[i] == -1) {
            if (!bfs(i, g, t)) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << t[i]+1 << " ";
    }
    // cout << "\n";
    
    return 0;
}