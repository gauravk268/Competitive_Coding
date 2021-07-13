int dx[8]={-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8]={-1, -2, -2, -1, 1, 2, 2, 1};
bool vis[505][505];

bool isValid(int x, int y, int a, int b){
  return (x>0 && y>0 && x<=a && y<=b);
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
  memset(vis, false, sizeof(vis)); 

  queue<pair<int, int>> q;
  q.push({C, D});

  int result=0;
  while(q.size()){
    int k=q.size();
    result++;
    while(k--){
      int x=q.front().first;
      int y=q.front().second;
      q.pop();
      vis[x][y]=true;

      if(x==E && y==F)  return result-1;

      for(int i=0; i<8; i++){
        int nx=x+dx[i], ny=y+dy[i];

        if(isValid(nx, ny, A, B) && !vis[nx][ny]){
          q.push({nx, ny});
          if(nx==E && ny==F)  return result;

          vis[nx][ny]=true;
        }
      }
    }
  }

  return -1;
}
