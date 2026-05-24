#include <bits/stdc++.h>

using namespace std;

void dfs(int current, int ignore_node, const vector<vector<int>>& adj, vector<bool>& visited) {
    if (current == ignore_node) return;
    
    visited[current] = true;
    
    for (int next_node = 0; next_node < adj.size(); ++next_node) {
        if (adj[current][next_node] == 1 && !visited[next_node]) {
            dfs(next_node, ignore_node, adj, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n; cin >> n;
        vector<vector<int>> m(n, vector<int>(n,0));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> m[j][k];
            }
        }

        vector<bool> init(n, false);
        dfs(0, -1, m, init);

        vector<vector<char>> ans(n, vector<char>(n, 'N'));

        for (int j = 0; j < n; j++) {
            vector<bool> reach(n, false);
            dfs(0, j, m, reach);
            for (int k = 0; k < n; k++) {
                if (init[k] && !reach[k]) {
                    ans[j][k] = 'Y';
                }
            }
        }
        cout << "Case " << i << ":\n";

        string separator = "+";
        for (int j = 0; j < 2*n -1; j++) {
            separator += "-";
        }
        separator += "+";

        for (int j = 0; j < n; j++) {
            cout << separator << "\n";
            cout << "|";
            for (int k = 0; k < n; k++) {
                cout << ans[j][k] << "|";
            }
            cout << "\n";            
        }
        cout << separator << "\n";
    }

    return 0;
}