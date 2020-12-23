#include<bits/stdc++.h>
using namespace std;

char ar[31][31];
bool vis[31][31];
int dist[31][31];
int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};
int N;

bool isValid(int x, int y)
{
    if(x<1 || x>N || y<1 || y>N)    return false;
    if(vis[x][y]==true || ar[x][y]=='T')    return false;
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

        for(int i=0; i<4; i++)
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

    cin>>N;
    int srcX, srcY, endX, endY;

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>ar[i][j];
            if(ar[i][j]=='S')   srcX=i, srcY=j;
            if(ar[i][j]=='E')   endX=i, endY=j;

            vis[i][j]=false;
        }
    }

    bfs(srcX, srcY);
    cout<<dist[endX][endY]<<endl;

    return 0;
}

/*

Input:
5
S P P P P
T P T P P
T P P P P
P T E T T
P T P T T

Output:
5

*/