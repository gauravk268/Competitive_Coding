int Solution::climbStairs(int n) {
    if(n<4) return n;

    int dp[n+1];
    for(int i=0; i<=n; i++){
        if(i<4) dp[i]=i;
        else dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}
