class Solution
{
public:
  void dfs(vector<vector<int>> &city, int cur, int vis[])
  {
    int n = city.size();
    for (int i = 0; i < n; i++)
    {
      if (city[cur - 1][i] == 1 && !vis[i + 1] && cur - 1 != i)
      {
        vis[i + 1] = 1;
        dfs(city, i + 1, vis);
      }
    }
  }

  int findCircleNum(vector<vector<int>> &city)
  {
    int n = city.size();
    int vis[n + 1];
    memset(vis, 0, sizeof(vis));

    int result = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (city[i][j] == 1 && !vis[j + 1])
        {
          vis[j + 1] = 1;
          dfs(city, j + 1, vis);
          result++;
        }
      }
    }

    return result;
  }
};