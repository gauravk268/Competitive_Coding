bool dfs(int node, int c, vector<vector<int>> &adj, int *vis, int *col)
{
	vis[node] = 1;
	col[node] = c;

	for(int child:adj[node])
	{
		if(vis[child]==0)
		{
		  bool res=dfs(child, c^1, adj, vis, col);
			if(res==false)
			    return false;
		}
		else if(col[node]==col[child])
		    return false;
	}

	return true;
}

int Solution::solve(int A, vector<vector<int>> &B) {
	vector<vector<int>> adj(A+1);
	int col[A+1], vis[A+1];

	for(int i=0; i<=A; i++){
		adj[i].clear();
		col[i]=-1;
		vis[i]=0;
	}

  for(auto &x:B){
    adj[x[1]].push_back(x[0]);
    adj[x[0]].push_back(x[1]);
  }

	bool flag=true;
  for(int i=1; i<=A; i++){
    if(!vis[i]){
			bool ans=dfs(i, 0, adj, vis, col);
    	if(ans==false)	flag=false;
		}
  }

  return flag;
}