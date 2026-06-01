#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases; cin >> test_cases;
    for (int tc = 0; tc < test_cases; tc++) {
        if (tc > 0) cout << "\n";

        string t, p; cin >> t >> p;
        int n = t.size();
        int m = p.size();
        vector<int> lps(m, 0);
        int j = 0;
        for (int i = 1; i < m; i++) {
            while (j > 0 && p[i] != p[j]) j = lps[j - 1];
            if (p[i] == p[j]) j++;
            lps[i] = j;
        }

        vector<int> pos;
        j = 0;
        for (int i = 0; i < n; i++) {
            while (j > 0 && t[i] != p[j]) j = lps[j - 1];
            if (t[i] == p[j]) j++;
            if (j == m) {
                pos.push_back(i - m + 2);
                j = lps[j - 1];
            }
        }

        if (pos.empty()) cout << "Not Found\n";
        else {
            cout << pos.size() << "\n";
            for (int i = 0; i < pos.size(); i++) {
                cout << pos[i] << (i + 1 == pos.size() ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}