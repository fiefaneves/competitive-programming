#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int c; cin >> c;
    while (c--) {
        int l, m;
        cin >> l >> m;
        int capacity = l * 100;
        queue<int> left;
        queue<int> right;
        while (m--) {
            int car_l;
            string side;
            cin >> car_l >> side;
            
            if (side == "left") {
                left.push(car_l);
            } else {
                right.push(car_l);
            }
        }

        int n = 0;
        bool is_left = true;

        while (!left.empty() || !right.empty()) {
            int curr = 0;
            if (is_left) {
                while (!left.empty() && curr + left.front() <= capacity) {
                    curr += left.front();
                    left.pop();
                }
            } else {
                while (!right.empty() && curr + right.front() <= capacity) {
                    curr += right.front();
                    right.pop();
                }
            }
            n++;
            is_left = !is_left;
        }
        cout << n << '\n';
    }
    

    return 0;
}