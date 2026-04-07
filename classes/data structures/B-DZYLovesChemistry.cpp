#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class UnionFind {
private:
    vector<int> p, rank;
    int numSets;
public:
    UnionFind(int n) {
        p.assign(n, 0); for (int i = 0; i < n; i++) p[i] = i;
        rank.assign(n, 0);
        numSets = n;
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
            numSets--;
        }
    }
    int numDisjointSets() { return numSets; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    UnionFind uf(n+1);
    int cc = n;
    
    for (size_t i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
    
        if (!uf.isSameSet(x,y)) {
            uf.unionSet(x,y);
            cc--;
        }
    }

    ll ans = 1LL << (n - cc);
    cout << ans << '\n';
    

    return 0;
}