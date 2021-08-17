int great(set<int> &s, int k)
{
  auto it = s.lower_bound(k);
  --it;
  return (*it);
}

int Solution::solve(vector<int> &A)
{
  int n = A.size(), result = 0;

  int maxRight[n + 1];
  maxRight[n] = 0;

  for (int i = n - 1; i >= 0; i--)
  {
    maxRight[i] = max(maxRight[i + 1], A[i]);
  }

  set<int> lowValue;
  lowValue.insert(INT_MIN);

  for (int i = 0; i < n - 1; i++)
  {
    if (maxRight[i + 1] > A[i])
    {
      result = max(result, great(lowValue, A[i]) + A[i] + maxRight[i + 1]);
      lowValue.insert(A[i]);
    }
  }

  return result;
}
