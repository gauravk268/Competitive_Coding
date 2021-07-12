int vis[105][105];
int dx[8]={-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8]={-1, -1, -1, 0, 1, 1, 1, 0};
int n, m, freq;

bool isValid(int x, int y){
  return (x>=0 && y>=0 && x<n && y<m);
}

void dfs(int x, int y, vector<vector<int> > &A){
    freq++;
  vis[x][y]=1;

  for(int i=0; i<8; i++){
    int nx=x+dx[i];
    int ny=y+dy[i];

    if(isValid(nx, ny) && A[nx][ny] && !vis[nx][ny]){
      vis[nx][ny]=1;
      dfs(nx, ny, A);
    }
  }
}

int Solution::solve(vector<vector<int> > &A) {
  n=A.size();
  m=A[0].size();

  memset(vis, 0, sizeof(vis));
  int result=0;
  for(int i=0; i<n; i++)  for(int j=0; j<m; j++){
      freq=0;
    if(!vis[i][j] && A[i][j])
      dfs(i, j, A);

    result=max(result, freq);
  }

  return result;
}