#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

pair<int,int> bfs(int s, int n) {
    vector<int> dist(n+1, -1);
    queue<int> q;

    q.push(s);
    dist[s] = 0;

    int farthest_node = s;
    int max_dist = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (dist[curr] > max_dist) {
            max_dist = dist[curr];
            farthest_node = curr;
        }

        for (auto neighbor : adj[curr]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    return {farthest_node, max_dist};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    
    if (n==1) { 
        cout << 0; 
        return 0; 
    }
    
    adj.resize(n+1);
    for (size_t i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    pair<int, int> p1 = bfs(1,n);
    pair<int, int> p2 = bfs(p1.first, n);

    cout << p2.second;

    return 0;
}