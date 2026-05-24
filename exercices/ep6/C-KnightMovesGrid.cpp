#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<vector<int>> b(n, vector<int>(n,-1));
    queue<pair<int,int>> q;

    vector<int> dx = {-2, -2, -1, -1,  1,  1,  2,  2};
    vector<int> dy = {-1,  1, -2,  2, -2,  2, -1,  1};
    
    b[0][0] = 0;
    q.push({0,0});
    
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && b[nx][ny] == -1) {
                b[nx][ny] = b[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}