#include <bits/stdc++.h>

using namespace std;

// Backtracking com Poda (Pruning)

bool solve(int idx, int curr_sum, int target, const vector<int>& bars) {
    if (curr_sum == target) return true;

    if (curr_sum > target || idx == bars.size()) return false;

    if (solve(idx+1, curr_sum + bars[idx], target, bars)) return true;

    if (solve(idx+1, curr_sum, target, bars)) return true;
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    for (size_t i = 0; i < t; i++) {
        int target; cin >> target;
        int n; cin >> n;

        vector<int> bars(n);
        for (size_t j = 0; j < n; j++) {
            cin >> bars[j];
        }

        if (solve(0, 0, target, bars)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}