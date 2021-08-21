#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxMatrixSum(vector<vector<int>> &mat)
  {
    int n = mat.size(), m = mat[0].size();

    long long sum = 0;
    int minValue = INT_MAX, neg = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        sum += abs(mat[i][j]);
        if (mat[i][j] < 0)
          neg++;

        minValue = min(minValue, abs(mat[i][j]));
      }
    }

    if (neg & 1)
    {
      return sum - 2 * minValue;
    }

    return sum;
  }
};