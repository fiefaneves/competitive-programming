#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> plli;
typedef pair<int, int> pii;

const long long INF = 1e18;

vector<ll> dijkstra(int s, int n, const vector<vector<pii>>& adj) {
    priority_queue<plli, vector<plli>, greater<plli>> pq;
    vector<ll> dist(n + 1, INF);

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& [v,w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vector<vector<pii>> g(n+1);

    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        g[x].push_back({y, w});
    }

    vector<ll> ans = dijkstra(1, n, g);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}