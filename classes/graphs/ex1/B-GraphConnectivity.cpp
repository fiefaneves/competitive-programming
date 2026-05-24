#include <bits/stdc++.h>

using namespace std;

struct Node {
    int idx;
    char val;
};

void dfs (int u, vector<vector<Node>>& g, vector<bool>& v) {
    v[u] = true;
    for (auto n : g[u]) {
        if (!v[n.idx]) {
            dfs(n.idx, g, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    string line;
    getline(cin, line);
    getline(cin, line);
    while (t--) {
        getline(cin, line);
        char max = line[0];
        int n = max - 'A' + 1;

        vector<vector<Node>> g(n);
        while (getline(cin, line) && line != "") {
            char u = line[0];
            char v = line[1];

            int u_idx = u - 'A';
            int v_idx = v - 'A';

            Node o;
            o.idx = u_idx;
            o.val = u;
            Node m;
            m.idx = v_idx;
            m.val = v;

            g[u_idx].push_back(m);
            g[v_idx].push_back(o);
        }

        vector<bool> visited(n, false);
        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(i, g, visited);
                ans++;
            }
        }
        cout << ans << "\n";

        if (t > 0) {
            cout << "\n";
        }
    }
    

    return 0;
}