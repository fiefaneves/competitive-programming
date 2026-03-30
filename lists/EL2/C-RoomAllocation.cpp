#include <bits/stdc++.h>

using namespace std;

struct Costumer {
    int arrival;
    int departure;
    int id;

    bool operator<(const Costumer& other) const {
        if (arrival != other.arrival) {
            return arrival < other.arrival;
        }

        return departure < other.departure;        
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<Costumer> costumers(n);
    for (size_t i = 0; i < n; i++) {
        cin >> costumers[i].arrival >> costumers[i].departure;
        costumers[i].id = i;
    }

    sort(costumers.begin(), costumers.end());
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    int rooms = 0;
    vector<int> ans(n);

    for (size_t i = 0; i < n; i++) {
        if (!pq.empty() && pq.top().first < costumers[i].arrival) {
            int room = pq.top().second;
            pq.pop();

            ans[costumers[i].id] = room;
            pq.push({costumers[i].departure, room});
        } else {
            rooms++;
            ans[costumers[i].id] = rooms;
            pq.push({costumers[i].departure, rooms});
        }
    }

    cout << rooms << '\n';
    for (size_t i = 0; i < n; i++) {
        cout << ans[i]  << " ";
    }
    cout << '\n';

    return 0;
}