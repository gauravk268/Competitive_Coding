
#include<bits/stdc++.h>
using namespace std;

vector<int> ar[1000001];
int level[1000001], vis[1000001], dist[1000001];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=1;
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();

        for(int child:ar[curr])
            if(vis[child]==0)
            {
            	dist[child]=dist[curr]+1;
                q.push(child);
                vis[child]=1;
                level[dist[child]]++;
            }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    // cin>>t;

    while(t--)
    {
        int n, m, a, b, q;
        cin>>n>>m;

        for(int i=1; i<=m; i++)
            cin>>a>>b, ar[a].push_back(b), ar[b].push_back(a);

        cin>>q;
        while(q--)
        {
	        memset(vis, 0, sizeof(vis));
	    	memset(level, 0, sizeof(level));
	    	memset(dist, 0, sizeof(dist));

        	cin>>a>>b;

        	bfs(a);

        	cout<<level[b]<<endl;
        }
    }

    return 0;
}

/*
input
9 10
1 2
2 3
1 7
2 4
3 4
4 7
7 8
9 7
7 6
5 6
3
4 2
5 3
2 1

output
4
4
3
*/