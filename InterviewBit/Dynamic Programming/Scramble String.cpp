int Solution::isScramble(const string A, const string B)
{
  int n = A.length(), m = B.length();
  if (n != m)
    return false;
  if (A == B)
    return true;

  string copy_A = A, copy_B = B;

  sort(copy_A.begin(), copy_A.end());
  sort(copy_B.begin(), copy_B.end());

  if (copy_A != copy_B)
  {
    return false;
  }

  for (int i = 1; i < n; i++)
  {
    bool a = isScramble(A.substr(0, i), B.substr(0, i));
    bool b = isScramble(A.substr(i), B.substr(i));

    bool c = isScramble(A.substr(0, i), B.substr(n - i));
    bool d = isScramble(A.substr(i), B.substr(0, n-i));

    if ((a && b) || (c && d))
      return true;
  }

  return false;
}
