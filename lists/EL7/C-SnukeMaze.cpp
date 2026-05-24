#include <bits/stdc++.h>

using namespace std;

char get_next (char c) {
    if (c=='s') return 'n';
    if (c=='n') return 'u';
    if (c=='u') return 'k';
    if (c=='k') return 'e';
    if (c=='e') return 's';
    return '?';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w; cin >> h >> w;
    vector<string> m(h);
    for (int i = 0; i < h; i++) {
        cin >> m[i];
    }

    if (m[0][0] != 's') {
        cout << "No\n";
        return 0;
    }
    
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    vector<vector<bool>> v(h, vector<bool>(w, false));
    queue<pair<int,int>> q;

    q.push({0,0});
    v[0][0] = true;

    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if (x == h-1 && y == w-1) {
            cout << "Yes\n";
            return 0;
        }

        char next = get_next(m[x][y]);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
        
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (!v[nx][ny] && m[nx][ny] == next) {
                    v[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}