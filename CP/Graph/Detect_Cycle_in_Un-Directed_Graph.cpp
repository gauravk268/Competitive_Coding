// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool flag;
int vis[10001], parent[10001];

void dfs(int n, int p, vector<int> adj[])
{
    vis[n]=1;
    
    for(auto child:adj[n])
    {
        if(!vis[child])
            parent[child]=n, dfs(child, n, adj);
        else
            if(parent[n]!=child)    flag=true;
    }
    
    parent[n]=0;
}

bool isCyclic(vector<int> adj[], int V)
{
    memset(vis, 0, sizeof(vis));
    memset(parent, 0, sizeof(parent));
    flag=false;
    
    for(int i=0; i<V && !flag; i++)
    {
        for(auto child:adj[i])
        {
            if(!vis[child])
                parent[child]= -1, dfs(child, i, adj);
        }
    }

    if(flag)    return true;
    return false;
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code End

/*

Input:
3
2 1
0 1
4 3
0 1 1 2 2 3
5 4
0 1 2 3 3 4 4 2

Output:
0
0
1

*/