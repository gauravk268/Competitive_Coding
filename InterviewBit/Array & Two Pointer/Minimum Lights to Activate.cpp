int Solution::solve(vector &A, int B)
{
  int i = 0, x = B, count = 0;

  while (i < A.size())
  {
    int j = i + B - 1;
    int x = 0;

    while (A[j] != 1 && j >= 0 && j >= (i - B + 1))
    {
      j-- ;
    }

    if (j >= 0 && j != (i - B) && A[j] == 1)
    {

      count++;
      i = j + B;
    }
    else
      return -1;
  }

  return count;
}