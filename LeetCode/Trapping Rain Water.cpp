class Solution {
public:
    int trap(vector<int>& building) {
        int n=building.size();
        if(n<3) return 0;
        
        int maxRight[n], maxLeft[n];

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

        int result=0;
        for(int i=0; i<n; i++){
            result += min(maxRight[i], maxLeft[i])-building[i];
        }

        return result;
    }
};