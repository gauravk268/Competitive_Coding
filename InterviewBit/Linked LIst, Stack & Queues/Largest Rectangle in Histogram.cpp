int Solution::largestRectangleArea(vector<int> &A)
{
  int n = A.size();
  if (n == 1)
    return A[0];

  int l[n], r[n];
  stack<int> s;

  for (int i = 0; i < n; i++)
  {
    while (s.size() && A[s.top()] >= A[i])
      s.pop();

    if (s.size())
      l[i] = s.top();
    else
      l[i] = -1;

    s.push(i);
  }

  while (s.size())
    s.pop();

  for (int i = n - 1; i >= 0; i--)
  {
    while (s.size() && A[s.top()] >= A[i])
      s.pop();

    if (s.size())
      r[i] = s.top();
    else
      r[i] = n;

    s.push(i);
  }

  int result = 0;
  for (int i = 0; i < n; i++)
  {
    result = max(result, A[i] * (r[i] - l[i] - 1));
  }

  return result;
}