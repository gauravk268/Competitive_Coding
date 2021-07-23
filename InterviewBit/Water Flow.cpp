int vis[1001][1001];
int n,m;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int flag;
int ans;

bool isvalid(int x , int y , vector<vector<int>>&A)
{
    if(x>=0 && y>=0 && x<n && y <m && vis[x][y] <= flag )
        return true;
    
    return false;
}

void dfs(int x , int y , vector<vector<int>>&A)
{
    if(flag == 0)
    {
        vis[x][y]=1;
    }
    else if(flag)
    {
        if(vis[x][y] == 1)
            ans++;
        
        vis[x][y]=2;
    }
    
    for(int i=0 ; i<4 ; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(isvalid(nx,ny,A))
        {
            if(A[nx][ny] >= A[x][y])
                dfs(nx,ny,A);
        }
    }
    
    return;
}

int Solution::solve(vector<vector<int> > &A) 
{
    memset(vis,0,sizeof(vis));
    
    n= A.size();
    m= A[0].size();
    
    flag=0;
    ans=0;

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if((i==0 || j == 0) && vis[i][j] == 0)
            {
                dfs(i,j,A);
            }
        }
    }
    
    flag=1;
    
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if((i == n-1 || j == m-1) && vis[i][j] <= flag)
            {
                dfs(i,j,A);
            }
        }
    }

    return ans;
}