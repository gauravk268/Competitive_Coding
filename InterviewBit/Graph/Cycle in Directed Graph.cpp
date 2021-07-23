int vis[100005];

void dfs(vector<vector<int>> &adj, int node, bool &ans){
  vis[node]=true;
  for(auto &x:adj[node]){
    if(!vis[x]){
      dfs(adj, x, ans);
    }else if(vis[x]==1) {
      ans=true;
    }
  }
  vis[node]=2;
}

int Solution::solve(int A, vector<vector<int>> &B) {
  memset(vis, false, sizeof(vis));
  vector<vector<int>> adj(A+1);

  for(auto &x:B)
    adj[x[0]].push_back(x[1]);
  
  bool ans=false;
  for(int i=1; i<=A; i++){
    if(!vis[i]) dfs(adj, i, ans);
    if(ans)  break;
  }

  return ans;
}