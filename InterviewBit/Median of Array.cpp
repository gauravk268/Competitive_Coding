double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
  int n = A.size(), m = B.size();
  if (n > m)
    return findMedianSortedArrays(B, A);

  int cut1, cut2;
  int low = 0, high = n;
  while (low <= high)
  {
    cut1 = (low + high) >> 1;
    cut2 = ((n + m) / 2) - cut1;

    int l1 = (cut1 == 0) ? INT_MIN : A[cut1 - 1];
    int l2 = (cut2 == 0) ? INT_MIN : B[cut2 - 1];

    int r1 = (cut1 == n) ? INT_MAX : A[cut1];
    int r2 = (cut2 == m) ? INT_MAX : B[cut2];

    if (l1 > r2)
      high = cut1 - 1;
    else if (l2 > r1)
      low = cut1 + 1;
    else
    {
      if ((n + m) & 1)
        return min(r1, r2) * 1.0;
      else
        return (max(l1, l2) + min(r1, r2)) / 2.0;
    }
  }

  return 0.0;

  // Do not write main() function.
  // Do not read input, instead use the arguments to the function.
  // Do not print the output, instead return values as specified
  // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}