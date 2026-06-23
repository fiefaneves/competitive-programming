#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> adj;
vector<int> match_girl; 
vector<bool> vis;

bool dfs(int boy) {
    for (int girl : adj[boy]) {
        if (vis[girl]) continue;
        vis[girl] = true;
        if (match_girl[girl] == 0 || dfs(match_girl[girl])) {
            match_girl[girl] = boy;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    adj.assign(n + 1, vector<int>());
    match_girl.assign(m + 1, 0);
    
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int max_pairs = 0;
    
    for (int i = 1; i <= n; i++) {
        vis.assign(m + 1, false);
        if (dfs(i)) max_pairs++;
    }
    cout << max_pairs << "\n";
    
    for (int i = 1; i <= m; i++) {
        if (match_girl[i] != 0) {
            cout << match_girl[i] << " " << i << "\n";
        }
    }

    return 0;
}