class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      int n=s.length();
      string tmp="";
      for(int i=0; i<n-1; i++){
        tmp+=s[i];
        bool flag=true;
        for(int j=i+1; j<n; j+=tmp.length()){
          if(s.substr(j, tmp.length()) != tmp){
            flag=false;
            break;
          }
        }
        if(flag)  return true;
      }  
      
      return false;
    }
};