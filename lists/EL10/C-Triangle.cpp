#include <bits/stdc++.h>

using namespace std;

int dist (int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool check (int x1, int y1, int x2, int y2, int x3, int y3) {
    vector<int> d(3);
    d[0] = dist(x1, y1, x2, y2);
    d[1] = dist(x2, y2, x3, y3);
    d[2] = dist(x3, y3, x1, y1);

    sort(d.begin(), d.end());

    return (d[0] > 0 && d[0] + d[1] == d[2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> x(3), y(3);
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

    if (check(x[0], y[0], x[1], y[1], x[2], y[2])) {
        cout << "RIGHT\n";
        return 0;
    }

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int newX = x[i] + dx[j];
            int newY = y[i] + dy[j];

            if (check(newX, newY, x[(i + 1) % 3], y[(i + 1) % 3], x[(i + 2) % 3], y[(i + 2) % 3])) {
                cout << "ALMOST\n";
                return 0;
            }
        }
    }

    cout << "NEITHER\n";
    return 0;
}