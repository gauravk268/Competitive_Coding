int Solution::sqrt(int A) {
  if(A<2) return A;
  int low = 0, high = A, mid, ans = 0;

  while (low <= high)
  {
    mid = low + (high - low) / 2;

    if (mid == A / mid)
    {
      ans = mid;
      break;
    }

    if (mid < A / mid)
    {
      ans = mid;
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return ans;
}
