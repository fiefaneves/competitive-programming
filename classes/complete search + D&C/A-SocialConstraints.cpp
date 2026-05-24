#include <bits/stdc++.h>

using namespace std;

struct Constraint {
    int a, b, c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    while (cin >> n >> m && (n!=0 || m!=0)) {
        vector<Constraint> r(m);
        for (size_t i = 0; i < m; i++) {
            cin >> r[i].a >> r[i].b >> r[i].c;
        }

        vector<int> p(n);
        iota(p.begin(), p.end(), 0);

        int valids = 0;

        do {
            bool is_valid = true;

            for (size_t i = 0; i < m; i++) {
                int posA, posB;

                for (size_t j = 0; j < n; j++) {
                    if (p[j] == r[i].a) posA = j;
                    if (p[j] == r[i].b) posB = j;
                }

                int d = abs(posA - posB);

                if (r[i].c > 0 && d > r[i].c) {
                    // If c is positive then teenagers a and b must sit at most c seats apart.
                    is_valid = false;
                    break;
                } else if (r[i].c < 0 && d < -r[i].c) {
                    // If c is negative, then a and b must sit at least −c seats apart.
                    is_valid = false;
                    break;
                }
            }
            
            if (is_valid) {
                valids++;
            }
            
        } while (next_permutation(p.begin(), p.end()));

        cout << valids << '\n';
    }
    
    return 0;
}