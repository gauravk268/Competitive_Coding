int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};
bool vis[1005][1005];

bool isValid(int x, int y, int n, int m){
  return (x>=0 && y>=0 && x<n && y<m && !vis[x][y]);
}

void dfs(int x, int y, int n, int m, vector<string> &A){
  vis[x][y]=true;

  for(int i=0; i<4; i++){
    int nx=x+dx[i], ny=y+dy[i];

    if(isValid(nx, ny, n, m) && A[nx][ny]=='X'){
      vis[nx][ny]=true;
      dfs(nx, ny, n, m, A);
    }
  }
}

int Solution::black(vector<string> &A) {
  memset(vis, false, sizeof(vis));
  int n=A.size(), m=A[0].size();

  int count=0;
  for(int i=0; i<n; i++)  for(int j=0; j<m; j++){
    if(!vis[i][j] && A[i][j]=='X'){
      vis[i][j]=true;
      dfs(i, j, n, m, A);
      count++;
    }
  }

  return count;
}
