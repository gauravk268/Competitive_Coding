class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string tmp=num;
        for(int i=0; i<tmp.length(); i++){
            tmp[i]='0'+change[tmp[i]-'0'];
        }
        
        for(int i=0; i<tmp.length(); i++){
            if(tmp[i] > num[i]){
                while(i<tmp.length() && tmp[i] >= num[i]){
                    num[i]=tmp[i];
                    i++;
                }

                return num;
            }
        }
        
        return num;
    }
};