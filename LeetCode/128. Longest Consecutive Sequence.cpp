class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        
        for(auto u: nums)
            mp[u]=1;
        
        for(auto u: mp){
          
            int cur=1;
            while(1){
                if(mp.find(u.first+cur)==mp.end()) break;
                int x = u.first+cur;
                cur+=mp[u.first+cur];
                mp.erase(x);
            }
            mp[u.first]=cur;
            ans=max(ans,cur);
        }
        return ans;
    }
};