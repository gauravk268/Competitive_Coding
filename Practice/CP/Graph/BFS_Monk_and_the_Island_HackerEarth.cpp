#include<bits/stdc++.h>
using namespace std;

vector<int> ar[10001];
int dist[10001], vis[10001];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dist[src]=0;
    vis[src]=1;
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();

        for(int child:ar[curr])
            if(vis[child]==0)
            {
                q.push(child);
                dist[child]=dist[curr]+1;
                vis[child]=1;
            }
    }
}

int main()
{
    int t, n, m, a, b;
    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        for(int i=1; i<=n; i++) ar[i].clear(), dist[i]= 0, vis[i]=0;

        while(m--)  cin>>a>>b, ar[a].push_back(b), ar[b].push_back(a);

        bfs(1);

        cout<<dist[n]<<endl;
    }
}

/*
Input
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2

Expected Correct Output
2
2
*/