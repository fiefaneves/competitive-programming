#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

class SegmentTree {
private:
    int n;
    vector<long long> A, sum_st;

    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {
        if (L == R) {
            sum_st[p] = A[L];
        } else {
            int mid = (L + R) / 2;
            build(left(p), L, mid);
            build(right(p), mid + 1, R);
            
            sum_st[p] = sum_st[left(p)] + sum_st[right(p)];
        }
    }

    long long rsq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return 0;
        if (L >= i && R <= j) return sum_st[p];
        int mid = (L + R) / 2;
        return rsq(left(p), L, mid, i, j) + rsq(right(p), mid + 1, R, i, j);
    }

public:
    SegmentTree(const vector<long long>& initialA) {
        n = initialA.size();
        A = initialA;
        sum_st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    long long RSQ(int i, int j) {
        return rsq(1, 0, n - 1, i, j);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q; cin >> n >> q;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    SegmentTree st(v);

    int x, y;

    while (cin >> x >> y) {
        cout << st.RSQ(x-1, y-1) << '\n';
    }

    return 0;
}