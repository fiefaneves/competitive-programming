#include <bits/stdc++.h>

using namespace std;

const int MAX_VAL = 1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> freq(MAX_VAL+1);

    int n; cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
        if (x > max) max = x;
    }

    for (int i = max; i >= 1; i--) {
        int m = 0;
        for (int j = i; j <= max; j+=i) {
            m += freq[j];
            if (m>=2) {
                cout << i;
                return 0;
            }
        }   
    }   
    

    return 0;
}