#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
    vector<int> p, rank, size;
    int numSets;
    int maxSize;

public:
    UnionFind(int n) {
        p.assign(n+1, 0); for (int i = 0; i <= n; i++) p[i] = i;
        rank.assign(n+1, 0);
        size.assign(n+1, 1);
        numSets = n;
        maxSize = 1;
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
            maxSize = max(maxSize, size[y]);
            numSets--;
        }
    }
    int numDisjointSets() { return numSets; }
    int getSize(int i) { return size[findSet(i)]; }
    int getMaxSize() { return maxSize; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    UnionFind uf(n);

    for (size_t i = 0; i < m; i++) {
        int a, b; cin >> a >> b;

        if(!uf.isSameSet(a,b)) {
            uf.unionSet(a,b);
        }

        cout << uf.numDisjointSets() << " " << uf.getMaxSize() << '\n';
    }

    return 0;
}