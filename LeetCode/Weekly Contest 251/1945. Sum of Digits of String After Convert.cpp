class Solution {
public:
    int getLucky(string s, int k) {
        vector<int> res;
        for(int i=0; i<s.length(); i++){
            res.push_back(s[i]-'a'+1);
        }
        
        int tmp;
        if(k){
            tmp=0;
            for(int i=0; i<res.size(); i++){
                while(res[i]){
                    tmp+=(res[i]%10);
                    res[i]=res[i]/10;
                }
            }
            k--;
        }
        
        while(k--){
            int t1=0;
            while(tmp){
                t1+=(tmp%10);
                tmp/=10;
            }
            tmp=t1;
        }
        
        return tmp;
    }
};