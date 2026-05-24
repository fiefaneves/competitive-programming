#include <bits/stdc++.h>

using namespace std;

int kanade (const vector<int>& arr) {
    int max = -1e9;
    int curr = 0;

    for (auto x : arr) {
        curr += x;
        if (max < curr) max = curr;
        if (curr < 0) curr = 0;
    }
    return max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while (cin >> n) {
        vector<vector<int>> matrix(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        
        int max_g = -1e9;
        for (int top = 0; top < n; top++) {
            vector<int> col_sums(n, 0);
            for (int bottom = top; bottom < n; bottom++) {
                for (int col = 0; col < n; col++) {
                    col_sums[col] += matrix[bottom][col];
                }

                int curr_max = kanade(col_sums);
                if (curr_max > max_g) max_g = curr_max;
            }
        }
        cout << max_g << "\n";
    }

    return 0;
}