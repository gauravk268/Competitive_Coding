class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        
        int k=(*mp.begin()).second;
        for(auto &x:mp){
            if(x.second != k)   return false;
        }
        
        return true;        
    }
};