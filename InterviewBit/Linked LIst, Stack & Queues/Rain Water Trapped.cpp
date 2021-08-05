int Solution::trap(const vector<int> &A)
{
  int n = A.size();
  if (n < 3)
    return 0;

  int l[n], r[n];

  l[0] = A[0];
  r[n - 1] = A[n - 1];

  for (int i = 1; i < n; i++)
    l[i] = max(A[i], l[i - 1]);

  for (int i = n - 2; i >= 0; i--)
    r[i] = max(A[i], r[i + 1]);

  int result = 0;
  for (int i = 0; i < n; i++)
  {
    int k = min(l[i], r[i]) - A[i];
    result += k;
  }

  return result;
}
