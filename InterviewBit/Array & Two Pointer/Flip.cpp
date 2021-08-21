vector<int> Solution::flip(string A)
{
  int n = A.size();
  int value[n];

  for (int i = 0; i < n; i++)
  {
    if (A[i] == '1')
      value[i] = -1;
    else
      value[i] = 1;
  }

  int maxEnd = 0, maxHere = 0, st = -1, en = -1, k = 0;

  for (int i = 0; i < n; i++)
  {
    maxHere += value[i];

    if (maxHere < 0)
    {
      k = i + 1;
      maxHere = 0;
    }

    if (maxEnd < maxHere)
    {
      maxEnd = maxHere;
      st = k;
      en = i;
    }
  }

  if (st != -1 && en != -1)
  {
    return {st + 1, en + 1};
  }

  return {};
}
