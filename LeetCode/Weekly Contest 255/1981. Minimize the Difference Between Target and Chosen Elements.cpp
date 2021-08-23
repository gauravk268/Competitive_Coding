#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[70][(70 * 70) + 5];

  int fun(vector<set<int>> &mat, int row, int sumTillNow, int target)
  {
    if (row >= mat.size())
    {
      return abs(sumTillNow - target);
    }

    if (dp[row][sumTillNow] == -1)
    {
      for (auto &x : mat[row])
      {
        if (dp[row][sumTillNow] == -1)
        {
          dp[row][sumTillNow] = fun(mat, row + 1, sumTillNow + x, target);
        }
        else
        {
          dp[row][sumTillNow] = min(dp[row][sumTillNow], fun(mat, row + 1, sumTillNow + x, target));
        }

        if (dp[row][sumTillNow] == 0 || sumTillNow + x > target)
        {
          break;
        }
      }
    }

    return dp[row][sumTillNow];
  }

  int minimizeTheDifference(vector<vector<int>> &mat, int target)
  {
    memset(dp, -1, sizeof(dp));

    vector<set<int>> value;
    for (int i = 0; i < mat.size(); i++)
    {
      set<int> tmp;

      for (int j = 0; j < mat[i].size(); j++)
      {
        tmp.insert(mat[i][j]);
      }

      value.push_back(tmp);
    }

    return fun(value, 0, 0, target);
  }
};