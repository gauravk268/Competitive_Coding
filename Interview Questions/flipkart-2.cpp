#include<bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const {
        int x = p1.first / p1.second;
        int y = p2.first / p2.second;
        return x < y;
    }
};

signed main() {
    int n, k;
    // n - no of initial grp
    // k - no of mics;
    cin >> n >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push({x, 1});
    }
    k = k - n;

    while(k--) {
        auto p = pq.top();
        pq.pop();
        p.second += 1;
        pq.push(p);
    }
    auto p = pq.top();
    cout << p.first / p.second << endl;
}