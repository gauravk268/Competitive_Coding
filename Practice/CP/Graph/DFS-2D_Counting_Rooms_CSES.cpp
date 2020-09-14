#include<bits/stdc++.h>
using namespace std;

char ar[1001][1001];
bool vis[1001][1001];
int N, M;

bool isValid(int x, int y)
{
    if(x<1 || x>N || y<1 || y>M)    return false;
    if(vis[x][y]==true || ar[x][y]=='#')    return false;
    return true;
}

void dfs(int x, int y)
{
    vis[x][y]=true;

    if(isValid(x-1, y)) dfs(x-1, y);
    if(isValid(x+1, y)) dfs(x+1, y);
    if(isValid(x, y-1)) dfs(x, y-1);
    if(isValid(x, y+1)) dfs(x, y+1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
            cin>>ar[i][j];
    }

    int rooms=0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(ar[i][j]=='.' && vis[i][j]==false)
                dfs(i, j), rooms++;
        }
    }

    cout<<rooms<<endl;

    return 0;
}

/*

Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3

*/