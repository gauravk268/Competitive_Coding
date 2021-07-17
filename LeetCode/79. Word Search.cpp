class Solution
{
public:
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  bool vis[10][10];
  int n, m;

  bool isValid(int x, int y)
  {
    return (x >= 0 && y >= 0 && x < n && y < m);
  }

  bool dfs(int x, int y, vector<vector<char>> &A, string B, int index)
  {
    vis[x][y]=true;
    if (index == B.length())
      return true;
    
    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i], ny = y + dy[i];
      
      if (isValid(nx, ny) && !vis[nx][ny] && A[nx][ny] == B[index])
      { 
        if (dfs(nx, ny, A, B, index + 1))
          return true;
      }
    }
    
    vis[x][y]=false;
    return false;
  }

  bool exist(vector<vector<char>> &A, string B)
  {
    n = A.size(), m = A[0].size();

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
      {
        memset(vis, false, sizeof(vis));
        if (A[i][j] == B[0] && dfs(i, j, A, B, 1))
          return 1;
      }

    return 0;
  }
};
