#include <bits/stdc++.h>

using namespace std;

// next_permutation com um algoritmo recursivo de Backtracking.

bool solve(int idx, int curr_val, const vector<int>& a) {
    if (idx==5) return curr_val == 23;

    if (solve(idx+1, curr_val + a[idx], a)) return true;

    if (solve(idx+1, curr_val - a[idx], a)) return true;

    if (solve(idx+1, curr_val * a[idx], a)) return true;

    return false;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> a(5);
    while (true) {
        int sum = 0;
        for (size_t i = 0; i < 5; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum == 0) break;

        sort(a.begin(), a.end());
        bool is_possible = false;

        do {
            if (solve(1, a[0], a)) {
                is_possible = true;
                break;
            }
        } while (next_permutation(a.begin(), a.end()));
     
        if (is_possible) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }

    return 0;
}