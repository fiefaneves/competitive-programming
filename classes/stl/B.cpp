#include <bits/stdc++.h>

using namespace std;

// codeforces - criar uma conta -> logar -> ferramentas de desenvolvedor (chrome) e colocar no vjudge

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t; cin >> t;

   for (size_t i = 0; i < t; i++) {
      int n; cin >> n;
      vector<int> v(2*n);
      int sum=0;

      for (size_t j = 0; j < (2*n); j++) {
         int a; cin >> a;
         v[j] = a;
      }
      sort(v.begin(), v.end());
      for (size_t k = 0; k < 2*n; k += 2) {
         sum += min(v[k], v[k+1]);
      }
      cout << sum << '\n';
   }

   return 0;
}