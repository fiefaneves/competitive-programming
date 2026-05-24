#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w; cin >> h >> w;
    vector<string> map(h);
    queue<pair<int, int>> mq;
    vector<vector<int>> m_dist(h, vector<int>(w, INF));

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<char> dir = {'D', 'U', 'R', 'L'};

    int start_x = -1, start_y = -1;

    for (int i = 0; i < h; i++) {
        cin >> map[i];
        for (int j = 0; j < w; j++) {
            if (map[i][j] == 'A') {
                start_x = i;
                start_y = j;
            } else if (map[i][j] == 'M') {
                mq.push({i,j});
                m_dist[i][j] = 0;
            }
        }
    }

    while (!mq.empty()) {
        auto [x,y] = mq.front();
        mq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] != '#') {
                if (m_dist[nx][ny] == INF) {
                    m_dist[nx][ny] = m_dist[x][y] + 1;
                    mq.push({nx, ny});
                }
            }
        }
    }

    queue<pair<int, int>> pq;
    vector<vector<int>> p_dist(h, vector<int>(w, INF));
    vector<vector<int>> parent(h, vector<int>(w, -1));

    pq.push({start_x, start_y});
    p_dist[start_x][start_y] = 0;
    
    int end_x = -1, end_y = -1;
    
    while (!pq.empty()) {
        auto [x, y] = pq.front();
        pq.pop();
        
        if (x == 0 || x == h - 1 || y == 0 || y == w - 1) {
            end_x = x;
            end_y = y;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && map[nx][ny] != '#') {
                if (p_dist[nx][ny] == INF && p_dist[x][y] + 1 < m_dist[nx][ny]) {
                    p_dist[nx][ny] = p_dist[x][y] + 1;
                    parent[nx][ny] = i;
                    pq.push({nx, ny});
                }
            }
        }
    }

    if (end_x != -1) {
        cout << "YES\n";
        string path = "";
        int cx = end_x, cy = end_y;

        while (cx != start_x || cy != start_y) {
            int d = parent[cx][cy];
            path += dir[d];
            cx -= dx[d];
            cy -= dy[d];
        }

        reverse(path.begin(), path.end());
        cout << path.length() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}