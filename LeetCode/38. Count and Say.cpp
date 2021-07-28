class Solution {
public:
    string countAndSay(int n) {
        if(n==1)    return "1";
        string ans=countAndSay(n-1), result="";
        
        for(int i=0; i<ans.length(); i++){
            int k=1;
            while(i+1<ans.length() && ans[i]==ans[i+1]){
                i++;
                k++;
            }
            result += k+'0';
            result += ans[i];
        }
        
        return result;
    }
};
