#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int x; cin >> x;
    vector<pair<int, int>> v(n);

    int e;
    for (size_t i = 0; i < n; i++) {
        cin >> e;
        v[i] = {e, i+1};
    }

    sort(v.begin(), v.end());

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = v[left].first + v[right].first;

        if (sum == x) {
            cout << v[right].second << " " << v[left].second << '\n';
            return 0;
        } 
        else if (sum < x) {
            left++;
        } 
        else {
            right--;
        }
    }
    cout << "IMPOSSIBLE";
        
    return 0;
}