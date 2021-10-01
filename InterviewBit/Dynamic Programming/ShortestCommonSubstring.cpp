    
    int cost(string &s, string &t) {
        int n = s.length();
        int m = t.length();
        
        int ans = n + m;
        
        for(int len = 1; len <= min(n, m); len++) {
            int i = n - len;
            int j = 0;
            
            bool isMatch = true;
            
            while(i < n and j < m) {
                if(s[i] != t[j]) {
                    isMatch = false;
                    break;
                }
                i++;
                j++;
            }
            if(isMatch) {
                ans = min(ans, n + m - len);
            }
        }
        return ans - n;
    }
     int dp[1<<18][18];
    int sol(int i,int mask,int n,vector<string>&words){
        if(mask==(1<<n)-1)return 0;
        int t=INT_MAX;
        if(dp[mask][i]!=-1)return dp[mask][i];
        for(int j=0;j<n;j++){
            if((mask&(1<<j))==0){
              int len=cost(words[i],words[j]);
              t=min(t,len+sol(j,mask|(1<<j),n,words));
            }
        }
        return dp[mask][i]=t;
    }
int Solution::solve(vector<string> &words) {
     memset(dp,-1,sizeof(dp));
        int res=INT_MAX;
        for(int i=0;i<words.size();i++){
         int t=words[i].length()+sol(i,1<<i,words.size(),words);
        res=res>=t?t:res;
        }
       return res;
}
