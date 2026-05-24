#include <bits/stdc++.h>

using namespace std;

// free -> .
// reserved -> *

vector<string> board(8);

bool col_has[8] = {false};
bool diag1_has[15] = {false};
bool diag2_has[15] = {false};
int valid = 0;

void solve (int r) {
    if (r == 8) {
        valid++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if(board[r][i] == '*') continue;

        if(!col_has[i] && !diag1_has[r-i+7] && !diag2_has[r+i]) {
            col_has[i] = true;
            diag1_has[r-i+7] = true;
            diag2_has[r+i] = true;

            solve(r+1);

            col_has[i] = false;
            diag1_has[r-i+7] = false;
            diag2_has[r+i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int k = 0; k < 8; k++) {
        cin >> board[k];
    }

    solve(0);

    cout << valid << "\n";

    return 0;
}