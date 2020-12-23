// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
vector<int> dfs(vector<int> g[], int N)
{
    vector<int> result;
    stack<int> s;
    int vis[10001]={0};
    
    if(N)   s.push(0);
   
    while(!s.empty())
    {
        int curr=s.top(); s.pop();
        if(vis[curr])   continue;
        
        result.push_back(curr);  vis[curr]=1;
        for(int i=g[curr].size()-1; i>=0; i--)
        {
            if(!vis[g[curr][i]])
            {
                s.push(g[curr][i]);
            }
        }
    }
    
    return result;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends

/*

Example:
Input:
2
5 4
0 1 0 2 0 3 2 4
4 3
0 1 1 2 0 3

Output:
0 1 2 4 3   
0 1 2 3

Explanation:
Testcase 1:
0 is connected to 1 , 2 , 3
1 is connected to 0
2 is connected to 0 and 4
3 is connected to 0
4 is connected to 2
so starting from 0 , dfs will be 0 1 2 4 3.

*/