#include<bits/stdc++.h>
using namespace std;

vector<int> ar[100001];
int in[100001], low[100001], vis[1000001], timer;
vector<pair<int, int>> edgeList;
bool hasBridge;

void dfs(int node, int par)
{
    vis[node]=1;
    in[node]=low[node]=timer++;

    for(int child:ar[node])
    {
        if(child == par)    continue;

        if(vis[child])
        {
            low[node]=min(low[node], in[child]);
            if(in[node] > in[child])
            {
                edgeList.push_back({node, child});
            }
        }
        else
        {
            dfs(child, node);
            if(low[child] > in[node])
            {
                hasBridge=true;
                return;
            }

            // forward edge node -> child
            edgeList.push_back({node, child});
            low[node]=min(low[node], low[child]);
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
        int n, m, a, b;
        cin>>n>>m;

        while(m--)
            cin>>a>>b, ar[a].push_back(b), ar[b].push_back(a);


        dfs(1, -1);

        if(hasBridge)
            cout<<0<<endl;
        else
            for(auto value:edgeList)
            {
                cout<<value.first<<" "<<value.second<<endl;
            }
    }

    return 0;
}

/*
input
6 8
1 2
2 3
1 3
4 5
4 6
5 6
2 4
3 5
output
1 2
2 3
3 1
4 5
5 6
6 4
4 2
3 5

input
6 7
1 2
2 3
1 3
4 5
4 6
5 6
2 4
output
0
*/