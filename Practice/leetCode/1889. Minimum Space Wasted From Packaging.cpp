class Solution {
public:
    int minWastedSpace(vector<int>&A, vector<vector<int>>& B){
        sort(A.begin(),A.end());
        long res=LONG_MAX, sumA=0, MOD=1e9+7;
        for(auto x:A)   sumA+=x;
        
        for(auto &x:B){
            sort(x.begin(), x.end());
            if(x.back() < A.back()) continue;
            long cur=0, i=0, j;
            for(auto k:x){
                j=upper_bound(A.begin()+i, A.end(), k)-A.begin();
                cur += k*(j-i);
                i=j;
            }
            res = min(res, cur);
        }   
        
        return (res!=LONG_MAX)?(res-sumA)%MOD:-1;
    }
};