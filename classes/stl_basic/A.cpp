// #include <bits/stdc++.h>

// using namespace std;

// conjuntos nao tem repetição -> set
// ordenar o vetor -> iterar e se achar algum diferente -> incrementar o contador

// int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    
//    int n;
//    cin >> n;
//    vector<int> v(n);
// 
//    for (size_t i = 0; i < n; i++){
//     int x;
//     cin >> v[i];
//    }
// 
//    sort(v.begin(), v.end());
// 
//    int c=0;
//    int old=v[0];
//    int curr=0;
//    int pos=0;
//    
//    while (pos < n){
//     curr = v[pos];
//     if (curr != old){
//         c++;
//         old = curr;
//     }
//     pos++;  
//    }
//  
//    cout << c << '\n';
//    
//    return 0;
// }

#include <bits/stdc++.h>

using namespace std;


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   
   int n;
   cin >> n;
   set<int> s;

    for (size_t i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size();
    
   return 0;
}