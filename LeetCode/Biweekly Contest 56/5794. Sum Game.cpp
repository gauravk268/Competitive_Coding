class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        priority_queue<int> maxH1, maxH2;

        int fsum=0, ssum=0, f1=0, s1=0;
        for(int i=0; i<n/2; i++){
            if(num[i]=='?')    fsum++;
            else{
                f1+=num[i]-'0';
            }
        }

        for(int i=n/2; i<n; i++){
            if(num[i]=='?')    ssum++;
            else{
                s1+=num[i]-'0';
            }
        }

        if(f1==s1){
            if(fsum==ssum){
                if(fsum==0) return false;
                else return true;
            }
            return true;
        }else{
            return !((fsum+ssum)& 1);
        }
        
        return true;
    }
};