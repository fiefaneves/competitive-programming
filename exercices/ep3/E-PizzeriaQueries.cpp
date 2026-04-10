#include <bits/stdc++.h>

using namespace std;


const long long INF = 1e18;

class SegmentTree {
private:
    int n;
    vector<long long> min_st;

    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(const vector<long long>& A, int p, int L, int R) {
        if (L == R) {
            min_st[p] = A[L];
        } else {
            int mid = (L + R) / 2;
            build(A, left(p), L, mid);
            build(A, right(p), mid + 1, R);
            min_st[p] = min(min_st[left(p)], min_st[right(p)]);
        }
    }

    void update(int p, int L, int R, int idx, long long val) {
        if (L == R) {
            min_st[p] = val;
        } else {
            int mid = (L + R) / 2;
            if (L <= idx && idx <= mid) {
                update(left(p), L, mid, idx, val);
            } else {
                update(right(p), mid + 1, R, idx, val);
            }
            min_st[p] = min(min_st[left(p)], min_st[right(p)]);
        }
    }

    long long rmq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return INF; 
        if (L >= i && R <= j) return min_st[p];
        
        int mid = (L + R) / 2;
        return min(rmq(left(p), L, mid, i, j), rmq(right(p), mid + 1, R, i, j));
    }

public:
    SegmentTree(const vector<long long>& A) {
        n = A.size();
        min_st.assign(4 * n, 0);
        build(A, 1, 0, n - 1);
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

    vector<long long> lc(n), rc(n);

    for (size_t i = 0; i < n; i++) {
        long long p; cin >> p;
        lc[i] = p - (i+1);
        rc[i] = p + (i+1);
    }

    SegmentTree lt(lc);
    SegmentTree rt(rc);

    for (size_t i = 0; i < q; i++) {
        int op, k; cin >> op;
        long long x;
        if (op == 1) {
            cin >> k >> x;
            lt.update(k-1, x-k);
            rt.update(k-1, x+k);
        } else if (op == 2) {
            cin >> k;
            long long cost_l = lt.RMQ(0, k-1) + k;
            long long cost_r = rt.RMQ(k-1, n-1) - k;

            cout << min(cost_l, cost_r) << '\n';
        }
    }
    
    return 0;
}