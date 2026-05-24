#include <bits/stdc++.h>

using namespace std;

int grid[9][9];

bool row_has[9][10];
bool col_has[9][10];
bool box_has[9][10];

int get_box_id(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

bool solve(int r, int c) {
    if (r == 9) return true;
    
    if (c == 9) return solve(r + 1, 0);
    
    if (grid[r][c] != 0) return solve(r, c + 1);

    for (int num = 1; num <= 9; num++) {
        int box_id = get_box_id(r, c);
        
        if (!row_has[r][num] && !col_has[c][num] && !box_has[box_id][num]) {
            
            grid[r][c] = num;
            row_has[r][num] = true;
            col_has[c][num] = true;
            box_has[box_id][num] = true;

            if (solve(r, c + 1)) return true;

            grid[r][c] = 0;
            row_has[r][num] = false;
            col_has[c][num] = false;
            box_has[box_id][num] = false;
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        for (int i = 0; i < 9; i++) {
            for (int num = 1; num <= 9; num++) {
                row_has[i][num] = false;
                col_has[i][num] = false;
                box_has[i][num] = false;
            }
        }

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cin >> grid[r][c];
                if (grid[r][c] != 0) {
                    int num = grid[r][c];
                    int box_id = get_box_id(r, c);
                    
                    row_has[r][num] = true;
                    col_has[c][num] = true;
                    box_has[box_id][num] = true;
                }
            }
        }

        if (solve(0, 0)) {
            for (int r = 0; r < 9; r++) {
                for (int c = 0; c < 9; c++) {
                    cout << grid[r][c] << (c == 8 ? "" : " ");
                }
                cout << "\n";
            }
        } else {
            cout << "No solution\n";
        }
    }
    return 0;
}