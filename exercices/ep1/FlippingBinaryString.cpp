#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> ones;
    vector<int> zeros;

    for (size_t i = 0; i < n; i++) {
        if (s[i] == '1') ones.push_back(i+1);
        else zeros.push_back(i+1);
    }

    if (ones.size() % 2 == 0) {
        cout << ones.size() << '\n';
        for (int idx : ones) {
            cout << idx << ' ';
        }
        cout << '\n';
    }

    else if (zeros.size() % 2 != 0) {
        cout << zeros.size() << '\n';
        for (int idx : zeros) {
            cout << idx << ' ';
        }
        cout << '\n';
    }

    else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (size_t i = 0; i < t; i++) {
        solve();
    }

    return 0;
}