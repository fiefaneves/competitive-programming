#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> cap;
vector<vector<int>> orig_edges;

int bfs (int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && cap[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, cap[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

bool dfs_path (int cur, vector<int>& path) {
    path.push_back(cur);
    if (cur == n) return true;
    for (int next : orig_edges[cur]) {
        if (cap[cur][next] == 0) {
            cap[cur][next] = 1;
            if (dfs_path(next, path)) return true;
        }
    }
    path.pop_back();
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    cap.assign(n + 1, vector<int>(n + 1, 0));
    orig_edges.assign(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += 1;
        orig_edges[u].push_back(v);
    }

    int max_flow = 0;
    vector<int> parent(n + 1);
    int new_flow;
    while ((new_flow = bfs(1, n, parent)) > 0) {
        max_flow += new_flow;
        int cur = n;
        while (cur != 1) {
            int prev = parent[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }

    cout << max_flow << "\n";

    for (int i = 0; i < max_flow; i++) {
        vector<int> path;
        dfs_path(1, path);
        cout << path.size() << "\n";
        for (int j = 0; j < path.size(); j++) {
            cout << path[j] << (j + 1 == path.size() ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}