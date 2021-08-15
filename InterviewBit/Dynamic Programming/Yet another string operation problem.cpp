int dp[1005][1005][2];

int fun(string &A, string &B, int &C, int l, int r, bool rot = false)
{
  if (l > r)
    return 0;
  if (l == r)
    return (A[l] != B[r]);

  int &ans = dp[l][r][rot];
  if (ans != -1)
    return ans;

  if (rot)
  {
    ans = (A[l] != B[r]) + (A[r] != B[l]) + fun(A, B, C, l + 1, r - 1, true);
  }
  else
  {
    ans = (A[l] != B[l]) + fun(A, B, C, l + 1, r);
    ans = min(ans, (A[r] != B[r]) + fun(A, B, C, l, r - 1));
    ans = min(ans, C + fun(A, B, C, l, r, true));
  }

  return ans;
}

int Solution::solve(string A, string B, int C)
{
  int n = A.size();
  memset(dp, -1, sizeof(dp));

  return fun(A, B, C, 0, n - 1, 0);
}