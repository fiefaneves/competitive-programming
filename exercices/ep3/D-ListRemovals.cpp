#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> A;

    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {
        if (L == R) {
            A[p] = 1;
        } else {
            int mid = (L + R) / 2;
            build(left(p), L, mid);
            build(right(p), mid + 1, R);
            
            A[p] = A[left(p)] + A[right(p)];
        }
    }

    int remove(int p, int L, int R, int idx) {
        A[p]--;

        if (L == R) {
            return L;
        }

        int mid = (L+R)/2;
        int al = A[left(p)];

        if (idx <= al) {
            return remove(left(p), L, mid, idx);
        } else {
            return remove (right(p), mid+1, R, idx - al);
        }
    }


public:
    SegmentTree(int sz) {
        n = sz;
        A.assign(4*n, 0);
        build(1, 0, n - 1);
    }

    int getRemove(int idx) {
        return remove(1, 0, n-1, idx);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> v(n);

    for (size_t i = 0; i < n; i++) {
        cin >> v[i];
    }

    SegmentTree st(n);

    for (size_t i = 0; i < n; i++) {
        int pos; cin >> pos;

        int idx = st.getRemove(pos);

        cout << v[idx] << " ";
    }  

    return 0;
}