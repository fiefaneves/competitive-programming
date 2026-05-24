#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    bool is_coherent = true;
    int ans = 0;
    
    vector<vector<bool>> rmv(n, vector<bool>(n, false));

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i==j || i==k || j==k) continue;
                if (d[i][k] + d[k][j] < d[i][j]) is_coherent = false;
                else if (d[i][k] + d[k][j] == d[i][j]) {
                    if (!rmv[i][j]) {
                        rmv[i][j] = true;
                        ans++;
                    }
                }
            }
        }
    }
    
    if (is_coherent) {
        cout << ans/2 << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}