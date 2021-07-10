class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int building[], int n){
        int maxLeft[n], maxRight[n];
        for(int i=0; i<n; i++)
        {
            if(i==0)    maxLeft[i]=building[i];
            else maxLeft[i]=max(building[i], maxLeft[i-1]);
        }
        
        for(int i=n-1; i>=0; i--)
        {
            if(i==n-1)    maxRight[i]=building[i];
            else maxRight[i]=max(building[i], maxRight[i+1]);
        }
        
        vector<int> amountWater(n);
        for(int i=0; i<n; i++)
            amountWater[i]=min(maxRight[i], maxLeft[i])-building[i];
            
        
        int temp=0, result=0;
        for(int i=0; i<n; i++)
        {
            if(amountWater[i]==0)
            {
                result+=temp;
                temp=0;
            }
            
            temp+=amountWater[i];
        }
        
        return result;
    }
};