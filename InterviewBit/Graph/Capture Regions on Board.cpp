bool flag;
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0} ;
bool vis[1003][1003];

bool isValid(int x, int y, int n, int m){
  return (x>=0 && y>=0 && x<n && y<m);
}

void dfs(int x, int y, vector<vector<char>> &A, vector<pair<int, int>> &que){
  vis[x][y]=true;
  int n=A.size(), m=A[0].size();
  if(x==n-1 || y==m-1 || x==0 || y==0)  flag=false;
  que.push_back({x, y});

  for(int i=0; i<4; i++){
    int nx=x+dx[i], ny=y+dy[i];
    
    if(isValid(nx, ny, n, m) && !vis[nx][ny] && A[nx][ny]=='O'){
      dfs(nx, ny, A, que);
    }
  }
}

void Solution::solve(vector<vector<char> > &A) {
  int n=A.size(), m=A[0].size();
  memset(vis, false, sizeof(vis));

  vector<pair<int, int>> que;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(!vis[i][j] && A[i][j]=='O'){
        flag=true;
        dfs(i, j, A, que);

        if(flag){
          for(auto &x:que){
            A[x.first][x.second]='X';
          }
        }
        que.clear();
      }
    }
  }
}