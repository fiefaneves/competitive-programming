#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

class SegmentTree {
private:
    int n;
    vector<int> A, min_st, sum_st;

    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {
        if (L == R) {
            min_st[p] = A[L];
            sum_st[p] = A[L];
        } else {
            int mid = (L + R) / 2;
            build(left(p), L, mid);
            build(right(p), mid + 1, R);
            
            min_st[p] = min(min_st[left(p)], min_st[right(p)]);
            sum_st[p] = sum_st[left(p)] + sum_st[right(p)];
        }
    }

    void update(int p, int L, int R, int idx, long long val) {
        if (L == R) {
            A[idx] = val;
            min_st[p] = val;
            sum_st[p] = val;
        } else {
            int mid = (L + R) / 2;
            if (L <= idx && idx <= mid) {
                update(left(p), L, mid, idx, val);
            } else {
                update(right(p), mid + 1, R, idx, val);
            }
            min_st[p] = min(min_st[left(p)], min_st[right(p)]);
            sum_st[p] = sum_st[left(p)] + sum_st[right(p)];
        }
    }

    long long rmq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return INF; 
        if (L >= i && R <= j) return min_st[p];
        int mid = (L + R) / 2;
        return min(rmq(left(p), L, mid, i, j), rmq(right(p), mid + 1, R, i, j));
    }

public:
    SegmentTree(const vector<int>& initialA) {
        n = initialA.size();
        A = initialA;
        min_st.assign(4 * n, 0);
        sum_st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void update(int idx, long long val) {
        update(1, 0, n - 1, idx, val);
    }

    long long RMQ(int i, int j) {
        return rmq(1, 0, n - 1, i, j);
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q; cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    SegmentTree st(v);

    int op, x, y;

    while (cin >> op >> x >> y) {
        if (op == 1) {
            st.update(x-1,y);
        } else if (op == 2) {
            cout << st.RMQ(x-1, y-1) << '\n';
        }
    }
        

    return 0;
}