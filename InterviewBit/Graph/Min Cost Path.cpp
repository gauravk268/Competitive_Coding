int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'D', 'R', 'U', 'L'};

bool isvalid(int x, int y)
{
  return !(x < 0 || y < 0 || x >= n || y >= m);
}

int Solution::solve(int a, int b, vector<string> &v)
{

  n = a, m = b;
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

  queue<pair<int, int>> q;

  q.push({0, 0});
  dist[0][0] = 0;

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int x1 = x + dx[i];
      int y1 = y + dy[i];

      if (isvalid(x1, y1))
      {
        int d;

        if (v[x][y] == dir[i])
          d = 0;
        else
          d = 1;

        if (d + dist[x][y] < dist[x1][y1])
        {
          dist[x1][y1] = d + dist[x][y];
          q.push({x1, y1});
        }
      }
    }
  }

  return dist[a - 1][b - 1];
}