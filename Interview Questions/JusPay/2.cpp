#include <bits/stdc++.h>
using namespace std;

pair<int, int> distance(vector<int>& adj, int aa, int bb) {
    unordered_map<int, int> mapp;  //node distance
    mapp.clear();
    int start = aa;
    int dis = 0;
    while (start != -1) {
        if (mapp.find(start) != mapp.end())
            break;
        else {
            mapp[start] = dis;
            dis++;
            start = adj[start];
        }
    }

    unordered_set<int> vis;
    vis.clear();
    int start2 = bb;
    int dist = 0;
    int fg = 0;
    while (start2 != -1) {
        if (vis.find(start2) != vis.end()) {
            break;
        } else {
            vis.insert(start2);
            if (mapp.find(start2) != mapp.end()) {
                fg = 1;
                dist = dist + mapp[start2];
                break;
            }
            start2 = adj[start2];
            dist++;
        }
    }
    if (fg == 0) {
        return {INT_MAX, -1};
    }
    // cout<<dist;
    return {dist, start2};
}

int solution(vector<int> arr, int s1, int s2) {
    pair<int, int> p = distance(arr, s1, s2);
    int p1 = p.first;
    int p2 = p.second;
    pair<int, int> q = distance(arr, s2, s1);
    int q1 = q.first;
    int q2 = q.second;
    //cout << p1 << ' ' << p2 << ' ' << q1 << ' ' << q2 << '\n';
    if (p1 <= q1)
        return p2;
    else
        return q2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> adj;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            adj.push_back(temp);
        }
        int aa, bb;
        cin >> aa >> bb;

        cout << solution(adj, aa, bb);
    }
    return 0;
}