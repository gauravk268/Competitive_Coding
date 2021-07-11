class Solution {
public:    
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        
        bool arr[26];
        memset(arr, false, sizeof(arr));
        
        int result=0;
        for(int i=0; i<n-1; i++){
            int l=0, r=n-1;
            
            set<char> alpha;
            if(!arr[s[i]-'a']){
                arr[s[i]-'a']=true;
                l=i;
                while(s[r]!=s[l])   r--;

                for(int j=l+1; j<r; j++){
                    alpha.insert(s[j]);
                }
            }
            
            result += alpha.size();
        }

        return result;
    }
};