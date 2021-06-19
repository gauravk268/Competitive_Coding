class Solution {
public:
    int fourSumCount(vector<int>& n1, vector<int>& n2, vector<int>& n3, vector<int>& n4) {
        unordered_map<int, int> ab;
        for(int i=0; i<n1.size(); i++){
            for(int j=0; j<n2.size(); j++){
                ab[n1[i]+n2[j]]++;
            }
        }
        
        int result=0;
        for(int i=0; i<n3.size(); i++){
            for(int j=0; j<n4.size(); j++){
                if(ab[0-n3[i]-n4[j]]!=0)
                    result+= ab[0-n3[i]-n4[j]];
            }
        }
        
        return result;
    }
};