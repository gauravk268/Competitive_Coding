#include<bits/stdc++.h>
using namespace std;

vector<int> ar[10001];
int in[10001], low[10001], vis[100001], timer;
set<int> AP;

void dfs(int node, int par)
{
    vis[node]=1;
    in[node]=low[node]=timer++;
    int child_cnt=0;

    for(int child:ar[node])
    {
        if(child==par)  continue;

        if(vis[child]==1)
        {
            low[node]=min(low[node], in[child]);
        }
        else
        {
            dfs(child, node);
            child_cnt++;
            low[node]=min(low[node], low[child]);
            if(in[node]<=low[child] && par!= -1)
            AP.insert(node);            
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b;

    while(true)
    {
        cin>>n>>m;
    
        if(!n && !m)
            break;
    
        for(int i=1; i<=n; i++) ar[i].clear(), vis[i]=0;
    
        AP.clear();
        timer=1;
    
        for(int i=1; i<=m; i++)
            cin>>a>>b, ar[a].push_back(b), ar[b].push_back(a);
    
        for(int i=1; i<=n; i++)
            if(vis[i] == 0)
                dfs(1, -1);
    
        cout<<AP.size()<<endl;
    }

    return 0;
}

/*
Input:
3 3
1 2
2 3
1 3
6 8
1 3
6 1
6 3
4 1
6 4
5 2
3 2
3 5
0 0

Output:
0
1
*/