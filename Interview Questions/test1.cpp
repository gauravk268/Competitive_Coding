#include<bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<vector<int>> ans;

void dfs(vector<int> adj[], int u, int dest, vector<int> &currPath) {
     visited[u] = 1;
    currPath.push_back(u);

    for(int v : adj[u]) {
        if(v == dest){
            currPath.push_back(v);
            ans.push_back(currPath);
            currPath.pop_back();
        }
        else if(!visited[v]){
            dfs(adj, v, dest, currPath);
        }
    }
    visited[u] = 0;
    currPath.pop_back();

}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    visited.assign(n + 1, 0);
    vector<int> curr;
    dfs(adj, 0, 0, curr);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}