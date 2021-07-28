class Solution {
public:
    int numTeams(vector<int>& r) {
        int result=0;
        for(int i=1; i<r.size()-1; i++){
            int ls=0, rs=0, lg=0, rg=0;
            
            for(int j=0; j<i; j++){
                if(r[j] > r[i]) lg++;
                else if(r[j] < r[i])    ls++;
            }
            
            for(int j=r.size()-1; j>i; j--){
                if(r[j] > r[i]) rg++;
                else if(r[j] < r[i])    rs++;
            }
            
            result += (ls*rg)+(lg*rs);            
        }
        
        return result;
    }
};
