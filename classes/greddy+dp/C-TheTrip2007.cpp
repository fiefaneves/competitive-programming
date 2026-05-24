#include <bits/stdc++.h>

using namespace std;

int get_k (const vector<int>& bags) {
    int k = 0;
    int current_count = 0;
    int current_val = -1;
    
    for (size_t i = 0; i < bags.size(); i++) {
        if (bags[i] == current_val) {
            current_count++;
        } else {
            current_val = bags[i];
            current_count = 1;
        }
        k = max(k, current_count);
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    bool first = true;

    while (n != 0) {
        if (!first) {
            cout << "\n";
        }
        first = false;

        vector<int> k(n);
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }

        sort(k.begin(), k.end());
        int v = get_k(k);
        vector<vector<int>> p(v);
        
        for (int i = 0; i < n; i++) {
            p[i%v].push_back(k[i]);
        }

        cout << v << "\n";
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < p[i].size(); j++) {
                cout << p[i][j] << (j + 1 == p[i].size() ? "" : " ");
            }
            cout << "\n";
        }
        cin >> n;
    }

    return 0;
}