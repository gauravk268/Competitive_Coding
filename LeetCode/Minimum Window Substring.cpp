class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int k=t.length();
        unordered_map<char, int> m;
        int count=0;
        for(int i=0;i<k;i++){
            if(++m[t[i]]==1)
                count++;
        }
            
        int i, j;
        i=j=0;
        
        int len=INT_MAX;
        int start;
        while(j<n){
            if(m.find(s[j])!=m.end()){
               if(--m[s[j]]==0)
                count--;
            }
            if(count>0)
                j++;
            else if(count==0){
                if(j-i+1<len){
                    len=j-i+1;
                    start=i;
                }
                while(count==0){
                    if(m.find(s[i])!=m.end()){
                        m[s[i]]++;
                        if(m[s[i]]==1){
                            count++;
                            if(j-i+1<len){
                                len=j-i+1;
                                start=i;
                            }
                            }
                            i++;
                        }
                    else
                        i++;
                    }      
                j++;
            }
        }
        if(len!=INT_MAX)
        return s.substr(start,len);
        
        return "";
    }
};
