#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

struct Node {
    int left=0;
    int right=0;
    int parent=0;
    ll S=0;
    ll ans=0;
};

vector<int> bfs(vector<Node>& tree) {
    vector<int> order;
    order.push_back(1);
    int head = 0;

    while (head < order.size()) {
        int u = order[head++];
        if (tree[u].left != 0) {
            tree[tree[u].left].parent = u;
            order.push_back(tree[u].left);
        }
        if (tree[u].right != 0) {
            tree[tree[u].right].parent = u;
            order.push_back(tree[u].right);
        }
    }
    return order;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<Node> tree(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> tree[i].left >> tree[i].right;
        }

        vector<int> order = bfs(tree);

        for (int i = (int)order.size()-1; i >= 0; i--) {
            int u = order[i];

            if (tree[u].left == 0 && tree[u].right == 0) {
                tree[u].S = 1;
            } else {
                ll s_left = tree[tree[u].left].S;
                ll s_right = tree[tree[u].right].S;
                tree[u].S = (s_left + s_right + 3) % MOD;
            }
        }
        
        tree[1].ans = tree[1].S;

        for (int i = 1; i < order.size(); i++) {
            int u = order[i];
            int p = tree[u].parent;

            tree[u].ans = (tree[p].ans + tree[u].S) % MOD;
        }

        for (int i = 1; i <= n; i++) {
            cout << tree[i].ans << (i == n ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}