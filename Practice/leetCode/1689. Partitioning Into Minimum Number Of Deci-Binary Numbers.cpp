class Solution {
public:
    int minPartitions(string n) {
        int result=0;
        for(auto x:n){
            result = max(result, x-'0');
        }
        
        return result;
    }
};