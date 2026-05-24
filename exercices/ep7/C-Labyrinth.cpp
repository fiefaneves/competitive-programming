#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vector<string> map(n);
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<char> dir = {'D', 'U', 'R', 'L'};

    int start_x = -1, start_y = -1;
    int end_x = -1, end_y = -1;

    for (int i = 0; i < n; i++) {
        cin >> map[i];
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'A') {
                start_x = i;
                start_y = j;
            } else if (map[i][j] == 'B') {
                end_x = i;
                end_y = j;
            }
        }
    }
    
    //bfs
    vector<vector<int>> p(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    q.push({start_x, start_y});
    map[start_x][start_y] = '#';
    bool is_end = false;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x==end_x && y == end_y) {
            is_end = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != '#') {
                map[nx][ny] = '#';
                p[nx][ny] = i;
                q.push({nx,ny});   
            }
        }
    }

    if (is_end) {
        cout << "YES\n";
        string path = "";
        while (end_x != start_x || end_y != start_y) {
            int d = p[end_x][end_y];
            path += dir[d];
            end_x -= dx[d];
            end_y -= dy[d];
        }
        reverse(path.begin(), path.end());
        cout << path.length() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}