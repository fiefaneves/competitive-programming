#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> cap;
vector<pair<int, int>> orig_edges;

int bfs(int s, int t, vector<int>& parent) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    cap.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += 1;
        cap[v][u] += 1;
        orig_edges.push_back({u, v});
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

    vector<bool> reachable(n + 1, false);
    queue<int> q;
    q.push(1);
    reachable[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (!reachable[next] && cap[cur][next] > 0) {
                reachable[next] = true;
                q.push(next);
            }
        }
    }

    for (auto edge : orig_edges) {
        int u = edge.first;
        int v = edge.second;        
        if (reachable[u] != reachable[v]) cout << u << " " << v << "\n";
    }

    return 0;
}