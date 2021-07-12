int dx[8]={-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8]={-1, -1, -1, 0, 1, 1, 1, 0};

string Solution::solve(int a, int b, int c, int d, vector<int> &e, vector<int> &f) {
  int grid[a+1][b+1];
  memset(grid, 0, sizeof(grid));

  for(int i=0; i<=a; i++){
    for(int j=0; j<=b; j++){
      for(int k=0; k<c; k++){
        if(sqrt(pow(e[k]-i, 2)+pow(f[k]-j, 2)) <= d){
          grid[i][j]=1;
          break;
        }
      }
    }
  }

  if(grid[0][0] || grid[a-1][b-1])  return "NO";

  queue<pair<int, int>> q;
  q.push({0, 0});
  while(q.size()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();

    if(x==a && y==b)  return "YES";

    for(int i=0; i<8; i++){
      int nx=x+dx[i];
      int ny=y+dy[i];

      if(nx>=0 && ny>=0 && nx<=a && ny<=b && !grid[nx][ny]){
        grid[nx][ny]=1;
        q.push({nx, ny});
      }
    }
  }

  return "NO";
}
