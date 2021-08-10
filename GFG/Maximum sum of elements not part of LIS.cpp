// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  int maxSumLis(int v[], int n)
  {
    int dp[2][n], sum = 0, longestDist = 1;

    dp[0][0] = 1;
    dp[1][0] = v[0];
    sum = v[0];

    for (int i = 1; i < n; i++)
    {
      dp[0][i] = 1;
      dp[1][i] = v[i];
      sum += v[i];

      for (int j = 0; j < i; j++)
      {
        if (v[j] < v[i])
        {
          if (dp[0][j] + 1 > dp[0][i])
          {
            dp[1][i] = dp[1][j] + v[i];
            dp[0][i] = dp[0][j] + 1;
          }
          else if (dp[0][j] + 1 == dp[0][i])
          {
            dp[1][i] = min(dp[1][i], v[i] + dp[1][j]);
          }

          longestDist = max(longestDist, dp[0][i]);
        }
      }
    }

    int minSum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      if (dp[0][i] == longestDist)
      {
        minSum = min(minSum, dp[1][i]);
      }
    }

    return sum - minSum;
  }
};

// { Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int Arr[n];
    for (int i = 0; i < n; i++)
      cin >> Arr[i];
    Solution obj;
    cout << obj.maxSumLis(Arr, n) << endl;
  }
  return 0;
} // } Driver Code Ends