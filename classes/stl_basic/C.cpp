#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &v, int e) {
    int index = -1;
    int low = 0;
    int high = v.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == e) {
            index = mid;
        }
        if (v[mid] < e) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return index;
}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   
   int n; cin >> n;
   int q; cin >> q;
   vector<int> v(n);
   int a;

   for (size_t i = 0; i < n; i++) {
    cin >> a;
    v[i] = a;    
   }
   
   for (size_t i = 0; i < q; i++) {
    cin >> a;
    cout << solve(v, a) << '\n';    
   }

   return 0;
}
