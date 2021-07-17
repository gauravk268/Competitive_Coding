int Solution::minDistance(string A, string B) {
  int n=A.length(), m=B.length();

  int dp[n+1][m+1];
  for(int i=0; i<=n; i++) for(int j=0; j<=m; j++){
    if(i==0){
      dp[i][j]=j;
    }else if(j==0){
      dp[i][j]=i;
    }else if(A[i-1]==B[j-1]){
      dp[i][j]=dp[i-1][j-1];
    }else{
      dp[i][j]=1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
    }
  }

  return dp[n][m];
}
