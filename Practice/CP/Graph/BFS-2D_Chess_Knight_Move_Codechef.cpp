#include<bits/stdc++.h>
using namespace std;

bool vis[10][10];
int dist[10][10];
int dx[]={2, 2, 1, 1, -1, -1, -2, -2};
int dy[]={-1, 1, -2, 2, -2, 2, -1, 1};
int endX, endY;

bool isValid(int x, int y)
{
    if(x<1 || x>8 || y<1 || y>8)    return false;
    if(vis[x][y]==true)    return false;
    return true;
}

void bfs(int srcX, int srcY)
{
    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    dist[srcX][srcY]=0;
    vis[srcX][srcY]=true;

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        int d=dist[x][y];
        q.pop();

        for(int i=0; i<8; i++)
        {
            int newX=x+dx[i];
            int newY=y+dy[i];

            if(isValid(newX, newY))
            {
                dist[newX][newY]=d+1;
                vis[newX][newY]=true;
                q.push({newX, newY});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));

        char a, b;
        cin>>a>>b;
        int srcX=a-'a'+1, srcY=b-'0';

        cin>>a>>b;
        int endX=a-'a'+1, endY=b-'0';

        bfs(srcX, srcY);

        cout<<dist[endX][endY]<<endl;
    }

    return 0;
}

/*

Input:
2
a1 b1
g8 f6

Output:
3
1


*/