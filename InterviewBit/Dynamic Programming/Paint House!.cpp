int Solution::solve(vector<vector<int>> &A)
{
  int n = A.size();
  int dp[n][3];
  memset(dp, 0, sizeof(dp));

  for(int i=0; i<n; i++){
    if(i==0){
      dp[i][0]=A[i][0];
      dp[i][1]=A[i][1];
      dp[i][2]=A[i][2];
    }else{
      dp[i][0]=A[i][0]+min(dp[i-1][1], dp[i-1][2]);
      dp[i][1]=A[i][1]+min(dp[i-1][0], dp[i-1][2]);
      dp[i][2]=A[i][2]+min(dp[i-1][0], dp[i-1][1]);
    }
  }

  return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
}
