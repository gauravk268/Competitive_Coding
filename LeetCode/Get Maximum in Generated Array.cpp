class Solution {
public:
    int getMaximumGenerated(int n) {
        int values[n+1], maxValue=1;
        
        if(n==0 || n==1){
            return n;
        }
        
        values[0]=0;
        values[1]=1;
        
        for(int i=2; i<n+1; i++){
            if(i&1){
                values[i] = values[i/2] + values[(i/2) + 1];
            }
            else{
                values[i] = values[i/2];
            }
            maxValue = max(maxValue, values[i]);
        }
        
        return maxValue;
    }
};