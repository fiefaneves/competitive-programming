#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class UnionFind {
private:
    vector<int> p, rank;
    vector<ll> size;

public:
    UnionFind(int n) {
        p.assign(n, 0); for (int i = 0; i < n; i++) p[i] = i;
        rank.assign(n, 0);
        size.assign(n, 1);
    }
    int findSet(int i) { return (p[i]==i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i,j)) {
            int x = findSet(i);
            int y = findSet(j);
            if (rank[x] > rank[y]) swap(x,y);
            p[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
            size[y] += size[x];
        }
    }
    ll getSize(int i) { return size[findSet(i)]; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (size_t i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    vector<ll> ans(m);
    UnionFind uf(n);
    ll curr = (n * (n - 1LL)) / 2LL;
    
    for (auto i = m - 1; i >= 0; i--) {
        ans[i] = curr;
        
        int u = edges[i].first;
        int v = edges[i].second;

        if(!uf.isSameSet(u,v)) {
            ll size_u = uf.getSize(u);
            ll size_v = uf.getSize(v);
            curr -= (size_u * size_v);

            uf.unionSet(u, v);
        }
    }
    
    for (size_t i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}