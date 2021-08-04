string Solution::solve(string A)
{
  queue<char> q;
  map<char, int> s;

  string result = "";
  for (int i = 0; i < A.length(); i++)
  {
    while (q.size() && s[q.front()] > 1)
      q.pop();

    if (q.empty())
    {
      if (s[A[i]] == 0)
        result += A[i];
      else
        result += "#";

      if (s[A[i]] == 0)
      {
        q.push(A[i]);
      }
    }
    else if (q.front() != A[i])
    {
      result += q.front();
      if (s[A[i]] == 0)
      {
        q.push(A[i]);
      }
    }
    else
    {
      if (q.size())
        q.pop();

      while (q.size() && s[q.front()] > 1)
        q.pop();

      if (q.size())
      {
        result += q.front();
        if (s[A[i]] == 0)
        {
          q.push(A[i]);
        }
      }
      else
      {
        result += "#";
        if (s[A[i]] == 0)
        {
          q.push(A[i]);
        }
      }
    }

    s[A[i]]++;
  }

  return result;
}
