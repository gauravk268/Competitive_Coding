class Solution
{
public:
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};

  bool isValid(int x, int y, int n, int m)
  {
    return (x >= 0 && y >= 0 && x < n && y < m);
  }

  bool fun(vector<vector<int>> &h, int k)
  {
    int n = h.size(), m = h[0].size();

    bool vis[n][m];
    memset(vis, false, sizeof(vis));

    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;

    while (q.size())
    {
      pair<int, int> cur = q.front();
      q.pop();

      int x, y;
      for (int i = 0; i < 4; i++)
      {
        x = cur.first + dx[i];
        y = cur.second + dy[i];

        if (isValid(x, y, n, m) && !vis[x][y] && abs(h[cur.first][cur.second] - h[x][y]) <= k)
        {
          if (x == n - 1 && y == m - 1)
            return true;

          vis[x][y] = true;
          q.push({x, y});
        }
      }
    }

    return false;
  }

  int minimumEffortPath(vector<vector<int>> &h)
  {
    int n = h.size(), m = h[0].size();

    if (n == 1 && m == 1)
      return 0;

    int low = 0, high = INT_MAX, result = 0, mid;
    while (low <= high)
    {
      mid = low + (high - low) / 2;
      if (fun(h, mid))
      {
        result = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return result;
  }
};