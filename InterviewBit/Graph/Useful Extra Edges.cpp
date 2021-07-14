int fun(vector<pair<int,int>>adj[] , int n , int src , int des)
{
    vector<int>dist(n+1,INT_MAX);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
    pq.push({0,src});
    dist[src]=0;
    
    while(!pq.empty())
    {
        int v = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        
        for(auto node : adj[v])
        {
            int child = node.first;
            int child_w = node.second;
            
            if(dist[child] > w + child_w)
            {
                dist[child] = w+child_w;
                pq.push({dist[child],child});
            }
        }
    }
    
    return dist[des];
}

int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    
    vector<pair<int,int>>adj[A+1];
    
    for(int i=0 ; i<B.size() ; i++)
    {
        adj[B[i][0]].push_back({B[i][1],B[i][2]});
    }
    
    int ans=INT_MAX;
    
    for(int i=0 ; i<E.size() ; i++)
    {
        if(E[i][0] >= A && E[i][1] >= A)
        continue;
        
        adj[E[i][0]].push_back({E[i][1],E[i][2]});
        adj[E[i][1]].push_back({E[i][0],E[i][2]});
        
        ans = min(ans,fun(adj,A,C,D));
        
        adj[E[i][0]].pop_back();
        adj[E[i][1]].pop_back();
    }
    
    if(ans == INT_MAX)
    return -1;
    
    return ans;
}