class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size();
        vector<int>dp(n,1);
        
        for(int i=1; i<n; i++)
        {
            if(s[i]==s[i-1])
                dp[i]+=dp[i-1];
        }
        long long mxm=0;
       
        for(int i=0; i<n; i++){
            mxm+=dp[i];
        }
        return mxm % 1000000007;
    }
};