// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool flag;
int vis[10001], inCycle[10001];

void dfs(int n, int p, vector<int> adj[])
{
    vis[n]=1;
    inCycle[n]=1;
    
    for(auto child:adj[n])
    {
        if(!vis[child])
            dfs(child, n, adj);
            
        if(child==n || inCycle[child]==1)   flag=true;
    }
    
    inCycle[n]=0;
}

bool isCyclic(int V, vector<int> adj[])
{
    memset(vis, 0, sizeof(vis));
    memset(inCycle, 0, sizeof(inCycle));
    flag=false;
    
    for(int i=0; i<V && !flag; i++)
    {
        for(auto child:adj[i])
        {
            if(!vis[child])
                dfs(child, i, adj);
        }
    }

    if(flag)    return true;
    return false;
}

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    
    while(t--){
        
        int v, e;
        cin >> v >> e;
        
        vector<int> adj[v];
        
        for(int i =0;i<e;i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        cout << isCyclic(v, adj) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends

/*

Input:
3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
4 3
0 1 2 3 3 2
Output:
1
0
1

*/