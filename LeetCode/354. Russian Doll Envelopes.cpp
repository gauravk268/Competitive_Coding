class Solution
{
public:
  int maxEnvelopes(vector<vector<int>> &e)
  {
    int n = e.size();
    sort(e.begin(), e.end());

    int dp[n], result = 0;
    for (int i = 0; i < n; i++)
      dp[i] = 1;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (e[j][0] < e[i][0] && e[j][1] < e[i][1])
          dp[i] = max(1 + dp[j], dp[i]);
      }

      result = max(result, dp[i]);
    }

    return result;
  }
};