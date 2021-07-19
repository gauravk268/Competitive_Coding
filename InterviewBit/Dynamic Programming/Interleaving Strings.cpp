int Solution::isInterleave(string A, string B, string C) {
    int a = A.size(), b = B.size(), c = C.size();
    
    if((a + b) != c){
        return 0;
    }
    
    vector<vector<int> > dp(a+1, vector<int>(b+1, 0));
    dp[0][0] = 1;
    
    for(int i = 1; i < dp.size(); i++){
        if(C[i-1] == A[i-1]){
            dp[i][0] = dp[i-1][0];
        }
    }
    
    for(int i = 1; i < dp[0].size(); i++){
        if(C[i-1] == B[i-1]){
            dp[0][i] = dp[0][i-1];
        }
    }
    
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if((C[i+j-1] == A[i-1]) && (C[i+j-1] == B[j-1])){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            else if(C[i+j-1] == A[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else if(C[i+j-1] == B[j-1]){
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    return dp[a][b];
}