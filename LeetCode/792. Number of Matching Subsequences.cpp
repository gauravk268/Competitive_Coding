class Solution {
public:
    unordered_map<string, int> subs;
    
    bool isSub(string s, string a){
        int n=s.length(), m=a.size();
        int i=0, j=0;
        
        while(i<n && j<m){
            if(s[i]==a[j]){
                i++, j++;
            }else   i++;
        }
        
        return j==m;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int result=0;
        unordered_map<string, int> mp;
        
        for(auto &x:words)  mp[x]++;
        
        
        for(auto &x:mp){
            if(isSub(s, x.first))   result+=x.second;
        }
        
        return result;
    }
};
