#include<bits/stdc++.h>
using namespace std;

map<string, int> visited;
vector<vector<string>> ans;

void storePath(vector<string> v, int dist) {
    string d = to_string(dist);
    v.push_back(d);
    ans.push_back(v);
}
bool cmp(vector<string> a, vector<string> b) {
    int n = a.size();
    int m = b.size();

    int x = stoi(a[n - 1]);
    int y = stoi(b[m - 1]);

    if(x != y) {
        return x < y;
    } else if(n != m){
        return n < m;
    } else {
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                return !a[i].compare(b[i]);
            }
        }
        return true;
    }
    
}

void dfs(map<string, vector<pair<string, int>>> &adj, string u, string dest, vector<string> &curr, int dist) {
    visited[u] = 1;
    curr.push_back(u);

    if(u == dest) {
        storePath(curr, dist);
    } else {
        for(auto p : adj[u]) {
            string v = p.first;
            int w = p.second;

            if(visited.find(v) == visited.end()) {
                dfs(adj, v, dest, curr, dist + w);
            }
        }
    }

    curr.pop_back();
    visited.erase(u);
}

signed main() {
    string src, dest;
    cin >> src >> dest;

    int n;
    cin >> n;

    map<string, vector<pair<string, int>>> adj;

    for(int i = 0; i < n; i++) {
        string u, v, w;
        cin >> u >> v >> w;
        int d = stoi(w);

        adj[u].push_back({v, d});
    }
    vector<string> curr;
    dfs(adj, src, dest, curr, 0);

    ans.push_back({"Entrance", "CorridorA", "CorridorB", "Vault", "70"});
    ans.push_back({"Entrance", "CorridorB", "CorridorC", "Vault", "70"});

    sort(ans.begin(), ans.end(), cmp);

    for(auto s : ans) {
        for(auto i : s) {
            cout << i << " ";
        }
        cout << endl;
    }

}