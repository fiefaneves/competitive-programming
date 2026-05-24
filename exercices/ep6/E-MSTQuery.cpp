#include <bits/stdc++.h>

using namespace std;


class UnionFind {
private:
    vector<int> parent, rank;
    int components;
public:
    UnionFind(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        components = n;
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); 
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
            components--;
            return true;
        }
        return false;
    }
    int get_components() const {
        return components;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q; cin >> n >> q;
    vector<UnionFind> ufs(10, UnionFind(n));
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        for (int j = w; j <= 9; j++) {
            ufs[j].unite(u,v);
        }
    }

    for (int i = 0; i < q; i++) {
        int u, v, w; cin >> u >> v >> w;
        for (int j = w; j <= 9; j++) {
            ufs[j].unite(u,v);
        }
        long long ans = n - 10;
        for (int j = 1; j <= 9; j++) {
            ans += ufs[j].get_components();
        }
        cout << ans << "\n";
    }

    return 0;
}