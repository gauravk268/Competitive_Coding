bool vis[251];
int n, low[251], tIN[251], timer, result;

void dfs(vector<vector<int>>& graph, int v, int p){
    vis[v]=true;
    tIN[v]=low[v]=timer++;

    for(auto to:graph[v]){
        if(to==p)    continue;
        if(vis[to])  low[v]=min(low[v], tIN[to]);
        else{
            dfs(graph, to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tIN[v])     result++;
        }
    }
}

int solve(vector<vector<int>>& graph) {
    n=graph.size();
    timer=0;
    result=0;

    memset(vis, false, sizeof(vis));
    memset(low, -1, sizeof(low));
    memset(tIN, -1, sizeof(tIN));

    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(graph, i, -1);
        }
    }

    return result;
}