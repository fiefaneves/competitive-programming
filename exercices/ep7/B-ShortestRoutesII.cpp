#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q; cin >> n >> m >> q;
    vector<vector<ll>> d(n+1, vector<ll>(n+1, INF));

    for (int i = 1; i <= n; i++) d[i][i] = 0;
    
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        ll w; cin >> w;
        d[x][y] = min(d[x][y], w);
        d[y][x] = min(d[y][x], w);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (d[j][i] < INF && d[i][k] < INF) {
                    d[j][k] = min(d[j][k], d[j][i]+d[i][k]);
                }
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if (d[a][b] == INF) cout << "-1\n";
        else cout << d[a][b] << "\n";
    }
    
    
    return 0;
}