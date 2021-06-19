class Solution
{
public:
  int n, m;

  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  bool isValid(int x, int y)
  {
    return (x >= 0 && y >= 0 && x < n && y < m);
  }

  int dist(pair<int, int> a, pair<int, int> b)
  {
    int x = pow(2, abs(a.first - b.first));
    int y = pow(2, abs(a.second - b.second));

    return pow(x + y, 0.5);
  }

  vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
  {
    n = mat.size(), m = mat[0].size();
    vector<vector<int>> result(n);

    for (int i = 0; i < n; i++)
    {
      result[i].assign(m, -1);
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cout << mat[i][j] << " ";
        if (mat[i][j] == 0)
          result[i][j] = 0;
        else
        {
          queue<pair<pair<int, int>, int>> q;
          q.push({{i, j}, 0});

          while (!q.empty())
          {
            pair<int, int> cur = q.front().first;
            int dis = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
              pair<int, int> nt = {cur.first + dx[k], cur.second + dy[k]};

              if (isValid(nt.first, nt.second))
              {
                if (mat[nt.first][nt.second] == 0)
                {
                  result[i][j] = dis + 1;
                  while (!q.empty())
                    q.pop();
                  break;
                  // }else if(result[nt.first][nt.second]!= -1){
                  //     result[i][j] = dist({i, j}, nt) + result[nt.first][nt.second];
                  //     while(!q.empty())  q.pop();
                  //     break;
                }
                else
                {
                  q.push({nt, dis + 1});
                }
              }
            }
          }
        }
      }
      cout << endl;
    }

    return result;
  }
};