const int MOD=1e9+7;

int Solution::numDecodings(string A){
  int n=A.length();

  int dp[n];
  memset(dp, 0, sizeof(dp));

  if(A[0]=='0') return 0;
  dp[0]=1;

  for(int i=1; i<n; i++){
    int k=stoi(A.substr(i-1, 2));
    if(A[i]=='0'){
      if(k>0 && k<27) dp[i]=dp[i-1];
      else return 0;
    }else if(k>0 && k<27 && k!=A[i]-'0'){
      dp[i]=dp[i-1]+dp[i-2];
    }else dp[i]=dp[i-1];
  }

  return dp[n-1]%MOD;
}