int fun(vector<int> &A, int x){
  int sum = A[0], i = 0, j = 0, n = A.size(), ans = 0;

  while (j < n && i < n)
  {
    if (sum <= x){
      ans += j - i + 1;
      j++;

      if (j < n)
        sum += A[j];
    }else{
      sum -= A[i];
      i++;
    }
  }

  return ans;
}

int Solution::numRange(vector<int> &A, int B, int C){
  return fun(A, C) - fun(A, B - 1);
}