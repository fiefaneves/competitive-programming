#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;

const ll INF = 1e18;

vector<int> dijkstra(int start, int n, const vector<vector<pii>>& adj) {
    priority_queue<plli, vector<plli>, greater<plli>> pq;
    vector<ll> dist(n + 1, INF);
    vector<int> pred(n + 1, -1);

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& [v,w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                pred[v] = u;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF) {
        return {-1};
    }

    int current = n;
    vector<int> path;
    while (current != -1) {
        path.push_back(current);
        if (current == start) break;
        current = pred[current];
    }
    return path;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<pii>> g(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    vector<int> p = dijkstra(1, n, g);
    if (p.size() == 1 && p[0] == -1) cout << -1 << "\n";
    else {
        for (int i = p.size() - 1; i >= 0; i--) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}