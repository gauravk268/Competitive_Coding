int Solution::isMatch(const string A, const string B) {
  int n=A.length(), m=B.length();

  bool dp[n+1][m+1];
  memset(dp, false, sizeof(dp));
  
  dp[0][0]=true;
  for(int i=0; i<=m; i++){
    if(B[i-1]=='*')
      dp[0][i]=dp[0][i-1];
  }

  for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
    if(A[i-1]==B[j-1] || B[j-1]=='?')   dp[i][j]=dp[i-1][j-1];
    else if(B[j-1]=='*')  dp[i][j]=dp[i-1][j] || dp[i][j-1];
  }
    
  return dp[n][m];
}
