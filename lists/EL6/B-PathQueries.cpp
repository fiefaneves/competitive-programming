#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> f;
vector<ll> sz;
ll current_pairs = 0;

int find_set(int v) {
    if (v == f[v]) return v;
    return f[v] = find_set(f[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a!=b) {
        if (sz[a] < sz[b]) swap(a, b);
        current_pairs -= sz[a] * (sz[a]-1)/2;
        current_pairs -= sz[b] * (sz[b]-1)/2;
        f[b] = a;
        sz[a] += sz[b];
        current_pairs += sz[a] * (sz[a]-1)/2;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vector<tuple<int,int,int>> edges(n-1);
    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
    }

    vector<pii> queries(m);
    for (int i = 0; i < m; i++) { 
        int q; cin >> q;
        queries[i] = {q, i};
    }

    sort(edges.begin(), edges.end());
    sort(queries.begin(), queries.end());
        
    f.resize(n+1);
    sz.resize(n+1, 1);
    
    for (int i = 0; i <= n; i++) {
        f[i] = i;
    }

    vector<ll> ans(m);
    int idx = 0;

    for (int i = 0; i < m; i++) {
        auto [p, id] = queries[i];
        while (idx < n-1) {
            auto [w, u, v] = edges[idx];
            if (w > p) break;
            union_sets(u, v);
            idx++;
        }

        ans[id] = current_pairs;
    }
    
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}